# Input Handling

The handling of input for this program will be done in two different manners, depending on the type of input being read. The two types of input include the data read at the time of program initialization, which includes the vehicle and fire station data, and the data seemingly handled in real-time, which includes the event data.

## `Vehicle` and `FireStation` Data Handling
Each of the `Vehicle` and `FireStation` classes will have factory classes that create individual instances of their respective classes. An input handler for each class will place data read from the input `csv` file onto a queue from which a worker thread may read and then subsequently instantiate the object. 

The reading of the data from both related input files will be handled in a sequential manner as the `FireStation` `csv` file must be read before the `Vehicle` file as it must be possible for a `Vehicle` object to directly reference a `FireStation` object while the inverse is not true. Therefore, all `FireStation` objects will be created using the worker thread pool and then the same worker thread pool will begin creating the `Vehicle` objects. 

Synchronization will be required to ensure no two threads attempt to create the same object. This will be ensured using lock-free programming techniques.

## `Event` Data Handling
This program is imitating an emergency dispatch system and thus the events should seemingly appear in real-time as there does not exist a manner of predicting true emergency situations. However, for the purposes of this program all events will be predetermined but will not appear to exist until their start time. 

This will be administered through a single thread which will read all event data from the input `csv` file into a queue of events will do nothing other than move these events from ont queue to another, from where the other worker threads may read and begin to process.

By having these events lay in a non-accessible state until such a time as they are occurring, real-time dispatching is mimicked as accurately as possible.

Once these events are moved from the dormant to active queue, they will be visible to the pool of worker threads at which point any of the worker threads may complete any portion of the work required to effectively dispatch the event. There will exist an appropriate number of events such that there will not exist a stark imbalance between the number of worker threads and the number of events requiring dispatching.