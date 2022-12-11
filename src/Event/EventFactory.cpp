#include "EventFactory.h"
#include <type_traits>

namespace LockFreeDispatch {


    std::vector<Vehicle> EventFactory::vehiclesMeetingRequirements(std::vector<Vehicle> *vehicleReqts,
                                                                   std::vector<Vehicle> *orderedVehicles) {
        std::vector<Vehicle> meetingRequirements;

        for (Vehicle vehicle : *orderedVehicles)
        {
            for (Vehicle reqt : *vehicleReqts)
            {
                if (std::is_same<typeof(vehicle), typeof(reqt)>::value
                    && vehicle.getCurNumCrew() >= reqt.getCurNumCrew()
                    && vehicle.getCurWaterVolumeLitres() >= reqt.getCurWaterVolumeLitres())
                {
                    meetingRequirements.push_back(vehicle);
                }
            }
        }
        return meetingRequirements;
    }

    void EventFactory::selectVehicles(std::vector<Vehicle> *vehicleReqts, std::vector<Vehicle> *orderedVehicles) {
        // TODO - implement function
    }

    bool EventFactory::modifyVehicleStatus(std::vector<Vehicle> *vehicleList) {
        // TODO - implement function
        return false;
    }


} // LockFreeDispatch