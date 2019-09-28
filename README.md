# Odometry TF republisher

Simple node to republish nav_msgs/Odometry to TF transforms. This can be useful
when playing back bag files for example.


## Topics

* `odom` (`nav_msgs/Odometry`) Input, subscribed to
* `/tf` Published to (using TF2)

## Parameters

* `~base_frame` (default: `base_footprint`) Child frame of published transform.
  Parent frame is copied from input message.
