#include <fstream>
#include <sstream>
#include <iostream>
#include <valarray>
#include <optional>
#include <memory>
#include "DistrictResources.h"
#include "../Vehicle/FireEngine.h"
#include "../Vehicle/FireLadder.h"

namespace LockFreeDispatch
{

    FireStation DistrictResources::findFireStation(uint32_t fireStationID)
    {
        // TODO - Evaluate whether std::find_if could improve performance here
        for (const auto & station : districtFireStations)
        {
            if (station->getFireStationID() == fireStationID)
            {
                return (const FireStation &) station;
            }
        }
        exit(-1);
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
                districtVehicles.push_back( std::make_unique<FireEngine>(FireEngine(vehicleId, location,
                                                                                    homeFireStation, maxNumCrew,
                                                                                    curNumCrew, maxWaterVolumeLitres,
                                                                                    curWaterVolumeLitres,
                                                                                    VehicleStatus::Available,
                                                                                    workFactor)));
#ifndef NDEBUG
                std::cout << "Adding vehicle #" << vehicleId << " to global list" <<std::endl;
#endif
            }
            else if (vehicleType == "Ladder")
            {
                districtVehicles.push_back( std::make_unique<FireLadder>(FireLadder(vehicleId, location,
                                                                                    homeFireStation, maxNumCrew,
                                                                                    curNumCrew, maxWaterVolumeLitres,
                                                                                    curWaterVolumeLitres,
                                                                                    VehicleStatus::Available,
                                                                                    workFactor)));
#ifndef NDEBUG
                std::cout << "Adding vehicle #" << vehicleId << " to global list" <<std::endl;
#endif
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

        for (const std::vector<std::string> & entry : stations)
        {
            if (header)
            {
                header = false;
                continue;
            }

            auto const x = stof(entry.at(1));
            auto const y = stof(entry.at(2));
            auto const location = Location(x, y);
            auto const stationId = stoi(entry.at(0));
            auto const maxCrew = stoi(entry.at(3));
            auto const curCrew = stoi(entry.at(4));

            districtFireStations.push_back( std::make_unique<FireStation>( FireStation(stationId, location, maxCrew, curCrew) ));

#ifndef NDEBUG
            std::cout << "Adding Fire Station #" << stationId << " to global list" << std::endl;
#endif
        }
    }

    void DistrictResources::processEventSampleData(const std::string &fileName, std::vector<Event> &pendingQueue)
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
                auto const eventID = stoi(entry.at(0));
                auto const startTime = Time::stringToTime(entry.at(1));
                auto const durationSeconds = stoi(entry.at(2));
                auto const location = Location(stof(entry.at(4)), stof(entry.at(5)));
                auto const vehicleRequirementsId = stoi(entry.at(6));
                pendingQueue.push_back(Event(eventID, startTime, durationSeconds, location, vehicleRequirementsId));

#ifndef NDEBUG
                std::cout << "Adding Event #" << entry.at(0) << " to pending queue" << std::endl;
#endif
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
            uint32_t vehicleReqtId = stoi(entry.at(0));

            std::string vehicleType = entry.at(1);
            auto const volWater = stof(entry.at(2));
            auto const numCrew = stoi(entry.at(3));

            if (vehicleType == "Engine")
            {
                vehicleRequirements[vehicleReqtId].push_back(std::make_unique<Vehicle> (FireEngine(numCrew, volWater)));
#ifndef NDEBUG
                std::cout << "Adding vehicle with Requirement ID: #" << vehicleReqtId << " to global list" << std::endl;
#endif
            }
            else if (vehicleType == "Ladder")
            {
                vehicleRequirements[vehicleReqtId].push_back(std::make_unique<Vehicle> (FireLadder(numCrew, volWater)));
#ifndef NDEBUG
                std::cout << "Adding vehicle with Requirement ID: #" << vehicleReqtId << " to global list" << std::endl;
#endif
            }

        }
    }

    std::vector<Vehicle *> DistrictResources::getVehicleRequirements(uint32_t eventID) const
    {
        std::vector<Vehicle *> curEventVehicleRequirements;

        for (const auto & reqt : vehicleRequirements.at(eventID))
        {
            curEventVehicleRequirements.push_back(reqt.get());
        }

        return curEventVehicleRequirements;
    }

    std::vector<Vehicle *> DistrictResources::getOrderedVehicleList(const Location &eventLocation)
    {
        // Copy pointers to districtVehicles
        std::vector<Vehicle*> orderedList;
        for (const auto & vehicle : districtVehicles)
        {
            orderedList.push_back(vehicle.get());
        }

        // Classic bubble sort, chosen for ease of implementation since there are always <64 vehicles
        // it will always run in O(1) time
        bool stillSorting = true;
        while (stillSorting)
        {
            stillSorting = false;
            for (size_t i = 0; i < orderedList.size()-1; i++)
            {
                if (Location::calculateDistance((orderedList)[i]->getVehicleLocation(), eventLocation) >
                Location::calculateDistance((orderedList)[i + 1]->getVehicleLocation(), eventLocation) ){
                    auto temp = orderedList[i];
                    orderedList[i] = orderedList[i + 1];
                    orderedList[i + 1] = temp;
                }
            }
        }
        return orderedList;
    }

} // LockFreeDispatch