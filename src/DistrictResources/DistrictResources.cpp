#include <fstream>
#include <sstream>
#include "DistrictResources.h"
#include "../Vehicle/FireEngine.h"
#include "../Vehicle/FireLadder.h"
#include "../Vehicle/Vehicle.h"
#include "../Event/Event.h"

namespace LockFreeDispatch {

    void DistrictResources::populateDistrictVehicles(const std::vector<Vehicle>& vehicles)
    {
        for (auto vehicle : vehicles)
        {
            districtVehicles.push_back(vehicle);
        }
    }

    void DistrictResources::populateDistrictFireStations(const std::vector<FireStation>& stations)
    {
        for (auto station : stations)
        {
            districtFireStations.push_back(station);
        }
    }

    FireStation DistrictResources::findFireStation(uint32_t fireStationID) {
        for (auto station : districtFireStations)
        {
            if (station.getFireStationID() == fireStationID)
            {
                return station;
            }
        }
        return {};
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
            Vehicle newVehicle{};
            if (vehicleType == "Engine")
            {
                newVehicle = *new FireEngine();
            }
            else if (vehicleType == "Ladder")
            {
                newVehicle = *new FireLadder();
            }

            newVehicle.setVehicleID(stoi(entry.at(0)));
            newVehicle.setHomeFireStation(findFireStation(stoi(entry.at(2))));
            newVehicle.setMaxNumCrew(stoi(entry.at(3)));
            newVehicle.setCurNumCrew(stoi(entry.at(4)));
            newVehicle.setMaxWaterVolumeLitres(stof(entry.at(5)));
            newVehicle.setCurWaterVolumeLitres(stof(entry.at(6)));
            newVehicle.setWorkFactor(stof(entry.at(7)));

            districtVehicles.push_back(newVehicle);
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
            newStation.setFireStationLocation(*newLocation);
            newStation.setMaxNumCrew(stoi(entry.at(3)));
            newStation.setCurNumCrew(stoi(entry.at(4)));

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
                Location newLocation{};
                newLocation.setXCoord(stof(entry.at(3)));
                newLocation.setYCoord(stof(entry.at(4)));
                newEvent.setLocation(newLocation);
                newEvent.addVehicleRequirementId(stoi(entry.at(5)));

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
                vehicleRequirements[vehicleReqtId].push_back(newReqt);
            }
        }
    }

    std::vector<Vehicle> *DistrictResources::getVehicleRequirements(uint32_t eventID) {
        return &vehicleRequirements[eventID];
    }

    std::vector<Vehicle> DistrictResources::getOrderedVehicleList(Location eventLocation) {
        std::vector<Vehicle> orderedList = districtVehicles;

        // Classic bubble sort, chosen for ease of implementation since there are always <64 vehicles
        // it will always run in O(1) time
        bool stillSorting = true;
        while (stillSorting)
        {
            stillSorting = false;
            for (size_t i = 0; i < orderedList.size()-1; i++)
            {
                if (Location::calculateDistance(orderedList[i].getVehicleLocation(), eventLocation) >
                Location::calculateDistance(orderedList[i + 1].getVehicleLocation(), eventLocation) ){

                    Vehicle temp = orderedList[i];
                    orderedList[i] = orderedList[i + 1];
                    orderedList[i + 1] = temp;
                    stillSorting = true;
                }
            }
        }
        return orderedList;

    }

} // LockFreeDispatch