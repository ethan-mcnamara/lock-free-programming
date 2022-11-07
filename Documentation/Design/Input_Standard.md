# Input Formatting

For the purposes of this project, all input to the dispatch system will be simulated and provided to the program at runtime. All data will be provided as comma-seperated value (`csv`) files, with each source of input being provided in a separate file. the sources of data include the available vehicles, the available fire stations, the events requiring dispatching over a pre-determined amount of time, and the vehicle requirements for the critical situations requiring dispatching. The below sections describe the format of the four `csv` files.

## `Vehicle` List
The first `csv` file taken as input to the program is the list of all vehicles available in the dispatch district. The following headers will be used for the file.

```csv
vehicleID,vehicleType,homeFireStation,maxNumCrew,curNumCrew,maxVolumeWaterLitres,curVolumeWaterLitres
```

The `vehicleType` refers to whether the vehicle is a `FireEngine` or `FireLadder` vehicle. 

This file does not necessarily need to be ordered in any manner, although organizing the `csv` file by `vehicleID` would allow for more convenient organization.

## `FireStation` List
The second `csv` file taken as input to the program contains a list of all fire stations in the dispatch district. Fire stations have a fixed location and therefore coordinates of the station are provided to the program at runtime. The following headers will be used for the file.

```csv
fireStationID,xCoord,yCoord,maxNumCrew
```

Like the `Vehicle` `csv` file, this file does not necessarily need to be ordered in any way, but organizing by `fireStationID` would be ideal.

## `Event` List
Compared to the two prior lists, the `Event` list will contain the most data, as a multitude of events are required to approximate an accurate dispatch system. While the `csv` file will be provided to the program at runtime, events must be handled in seemingly-real-time and must thus be ordered by `startTime` in ascending order. The following headers will be used for this `csv` file.

```csv
eventID,startTime,durationSeconds,eventType,[Location],[vehicleRequirementsID],[vehicleID],[fireStationID]
```

As there are two types of events and both have different attributes, there exist headers in this `csv` file that may not be applicable to every event. The `Location` and `vehicleRequirementsID` headers will only be populated for `CriticalSituation` events. The `vehicleID` and `fireStationID` headers will only be populated for `Maintenance` events.

The `vehicleRequirementsID` attribute refers to the `VehicleRequirements` List, which contains one or more vehicles associated with this ID.

## `VehicleRequirements` List
This list is an addition to the `Event` list that represents the vehicular requirements of a critical situation requiring dispatching. Due to situations frequently requiring multiple vehicles and the limitations of the `csv` file format, the list of requirements is removed from the `Event` list and will be stored in an accompanying file. The headers below will be used.

```csv
vehicleRequirementsID,vehicleType,waterVolume,numCrew
```

The `vehicleType` will be either `FireEngine` or `FireLadder` if a specific vehicle type is required and `Vehicle` if no specific vehicle type is required.

This file will be ordered by `vehicleRequirementsID` in ascending order, with the vehicles required for a situation stored in no specific order within the set of vehicles required for a situation.
