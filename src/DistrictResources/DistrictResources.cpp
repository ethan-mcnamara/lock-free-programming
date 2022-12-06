#include <fstream>
#include <sstream>
#include "DistrictResources.h"
#include "../Vehicle/FireEngine.h"
#include "../Vehicle/FireLadder.h"

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

        for (std::vector<std::string> entry : vehicles)
        {
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

        for (std::vector<std::string> entry : stations)
        {
            FireStation newStation{};

            auto newLocation = new Location();
            newLocation->setXCoord(stoi(entry.at(1)));
            newLocation->setYCoord(stoi(entry.at(2)));

            newStation.setFireStationID(stoi(entry.at(0)));
            newStation.setFireStationLocation(*newLocation);
            newStation.setMaxNumCrew(stoi(entry.at(3)));
            newStation.setCurNumCrew(stoi(entry.at(4)));

            districtFireStations.push_back(newStation);
        }
    }

    void DistrictResources::processEventSampleData(const std::string &fileName)
    {
        // TODO - implement function
    }

    void DistrictResources::processVehicleRequirementsSampleData(const std::string &fileName)
    {
        // TODO - implement function
    }

} // LockFreeDispatch