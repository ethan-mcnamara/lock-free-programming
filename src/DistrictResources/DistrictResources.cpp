#include <fstream>
#include <sstream>
#include <iostream>
#include <valarray>
#include <optional>
#include <memory>
#include "DistrictResources.h"
#include "../Vehicle/FireEngine.h"
#include "../Vehicle/FireLadder.h"
#include "../Vehicle/Vehicle.h"
#include "../Event/Event.h"

namespace LockFreeDispatch {

    FireStation DistrictResources::findFireStation(uint32_t fireStationID) {
        for (const auto & station : districtFireStations)
        {
            if (station.getFireStationID() == fireStationID)
            {
                return station;
            }
        }
        return FireStation{};
    }

    void DistrictResources::processVehicleSampleData(const std::string& fileName)
    {
        std::vector<std::vector<std::string>> vehicles;
        std::vector<std::string> row;
        std::string line, word;

        std::fstream file (fileName, std::ios::in);
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            vehicles.push_back(row);
        }

        bool header = true;

        for (std::vector<std::string> entry : vehicles)
        {
            if (header)
            {
                header = false;
                continue;
            }
            std::string vehicleType = entry.at(1);

            auto const vehicleId = stoi( entry.at( 0 ) );
            auto const homeFireStation = findFireStation( stoi( entry.at( 2 ) ) );
            auto const location = findFireStation(stoi(entry.at(2))).getFireStationLocation();
            auto const maxNumCrew = stoi(entry.at(3));
            auto const curNumCrew = stoi(entry.at(4));
            auto const maxWaterVolumeLitres = stof(entry.at(5));
            auto const curWaterVolumeLitres = stof(entry.at(6));
            auto const workFactor = stof(entry.at(7));

            if (vehicleType == "Engine")
            {
                districtVehicles.push_back( std::make_unique<FireEngine>( FireEngine(vehicleId, location,
                                                                          homeFireStation, maxNumCrew, curNumCrew, maxWaterVolumeLitres,
                                                                          curWaterVolumeLitres, VehicleStatus::Available, workFactor ) ));
                std::cout << "Adding vehicle #" << vehicleId << " to global list" <<std::endl;
            }
            else if (vehicleType == "Ladder")
            {
                districtVehicles.push_back( std::make_unique<FireLadder>( FireLadder(vehicleId, location,
                                                                                     homeFireStation, maxNumCrew, curNumCrew, maxWaterVolumeLitres,
                                                                                     curWaterVolumeLitres, VehicleStatus::Available, workFactor ) ));
                std::cout << "Adding vehicle #" << vehicleId << " to global list" <<std::endl;
            }
        }
    }

    void DistrictResources::processFireStationSampleData(const std::string &fileName)
    {
        std::vector<std::vector<std::string>> stations;
        std::vector<std::string> row;
        std::string line, word;

        std::fstream file (fileName, std::ios::in);
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            stations.push_back(row);
        }

        bool header = true;

        for (std::vector<std::string> entry : stations)
        {
            if (header)
            {
                header = false;
                continue;
            }

            FireStation newStation{};

            auto newLocation = new Location();
            newLocation->setXCoord(stof(entry.at(1)));
            newLocation->setYCoord(stof(entry.at(2)));

            newStation.setFireStationID(stoi(entry.at(0)));
            newStation.setFireStationLocation(newLocation);
            newStation.setMaxNumCrew(stoi(entry.at(3)));
            newStation.setCurNumCrew(stoi(entry.at(4)));

            std::cout << "Adding Fire Station #" << newStation.getFireStationID() << " to global list" << std::endl;
            districtFireStations.push_back(newStation);
        }
    }

    void DistrictResources::processEventSampleData(const std::string &fileName, std::vector<Event> *pendingQueue)
    {
        std::vector<std::vector<std::string>> events;
        std::vector<std::string> row;
        std::string line, word;

        std::fstream file (fileName, std::ios::in);
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            events.push_back(row);
        }

        bool header = true;

        for (std::vector<std::string> entry : events)
        {
            if (header)
            {
                header = false;
                continue;
            }
            std::string eventType = entry.at(3);
            if (eventType == "CriticalSituation")
            {
                Event newEvent = *new Event();
                newEvent.setEventID(stoi(entry.at(0)));
                newEvent.setStartTime(Time::stringToTime(entry.at(1)));
                newEvent.setDurationSeconds(stoi(entry.at(2)));
                Location *newLocation = new Location();
                newLocation->setXCoord(stof(entry.at(4)));
                newLocation->setYCoord(stof(entry.at(5)));
                newEvent.setLocation(newLocation);
                newEvent.addVehicleRequirementId(stoi(entry.at(6)));

                std::cout << "Adding Event #" << entry.at(0) << " to pending queue" << std::endl;

                pendingQueue->push_back(newEvent);
            }
        }
    }

    void DistrictResources::processVehicleRequirementsSampleData(const std::string &fileName)
    {
        std::vector<std::vector<std::string>> reqts;
        std::vector<std::string> row;
        std::string line, word;

        std::fstream file (fileName, std::ios::in);
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            reqts.push_back(row);
        }

        bool header = true;

        for (std::vector<std::string> entry : reqts)
        {
            if (header)
            {
                header = false;
                continue;
            }
            uint16_t vehicleReqtId = stoi(entry.at(0));

            if (entry.at(1) == "FireEngine")
            {
                FireEngine newReqt = FireEngine();
                newReqt.setCurWaterVolumeLitres(stof(entry.at(2)));
                newReqt.setCurNumCrew(stoi(entry.at(3)));
                if (vehicleRequirements.find(vehicleReqtId) == vehicleRequirements.end())
                {
                    vehicleRequirements[vehicleReqtId] = *new std::vector<Vehicle>;
                }
                std::cout << "Adding vehicle with Requirement ID: #" << vehicleReqtId << " to global list" << std::endl;
                vehicleRequirements[vehicleReqtId].push_back(newReqt);
            }
            else if (entry.at(1) == "FireLadder")
            {
                FireLadder newReqt = FireLadder();
                newReqt.setCurWaterVolumeLitres(stof(entry.at(2)));
                newReqt.setCurNumCrew(stoi(entry.at(3)));
                if (vehicleRequirements.find(vehicleReqtId) == vehicleRequirements.end())
                {
                    vehicleRequirements[vehicleReqtId] = *new std::vector<Vehicle>;
                }

                std::cout << "Adding vehicle with Requirement ID: #" << vehicleReqtId << " to global list" << std::endl;
                vehicleRequirements[vehicleReqtId].push_back(newReqt);
            }
        }
    }

    std::vector<Vehicle> *DistrictResources::getVehicleRequirements(uint32_t eventID) {
        return &vehicleRequirements[eventID];
    }

    double calculateDistance(Location *locationA, Location *locationB)
    {
        float xDist = locationA->getXCoord() - locationB->getXCoord();
        float yDist = locationA->getYCoord() - locationB->getYCoord();
        double xDistSquared = std::pow(xDist, 2.0);
        double yDistSquared = std::pow(yDist, 2.0);
        return std::sqrt(xDistSquared + yDistSquared);
    }

    std::vector<Vehicle> *DistrictResources::getOrderedVehicleList(Location *eventLocation) {
        std::vector<Vehicle> *orderedList = new std::vector<Vehicle> (districtVehicles);

        // Classic bubble sort, chosen for ease of implementation since there are always <64 vehicles
        // it will always run in O(1) time
        bool stillSorting = true;
        while (stillSorting)
        {
            stillSorting = false;
            for (size_t i = 0; i < orderedList->size()-1; i++)
            {
                if (Location::calculateDistance((*orderedList)[i].getVehicleLocation(), eventLocation) >
                Location::calculateDistance((*orderedList)[i + 1].getVehicleLocation(), eventLocation) ){
                    Vehicle temp = (*orderedList)[i];
                    (*orderedList)[i] = (*orderedList)[i + 1];
                    (*orderedList)[i + 1] = temp;
                }
                std::cout << "outside if statement" << std::endl;
            }
        }
        return orderedList;

    }

} // LockFreeDispatch