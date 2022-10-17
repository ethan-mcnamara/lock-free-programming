#ifndef CMAKE_LOCK_FREE_PROGRAMMING_CRITICALSITUATION_H
#define CMAKE_LOCK_FREE_PROGRAMMING_CRITICALSITUATION_H

#include "Event.h"
#include "../Location/Location.h"
#include "../Vehicle/Vehicle.h"
#include <vector>

namespace LockFreeDispatch {

    class CriticalSituation : public Event {
        private:
            Location eventLocation;
            std::vector<Vehicle*> vehicleRequirements;

        public:

            Location getLocation();

            void setLocation(Location newLocation);

            std::vector<Vehicle*> getVehicleRequirements();

            void addVehicleRequirement(Vehicle* newVehicleRequirement);

            Vehicle *popVehicleRequirement();

            void deleteVehicleRequirements();

            bool findVehicleRequirement(Vehicle *vehicle);
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_CRITICALSITUATION_H
