# Odometry TF republisher

**NOTE**: I no longer work in the field of robotics, this is not maintained. But
hopefully the ideas and techniques presented here might be of use to you. Or the
software itself might even still work!

---

Simple node to republish nav_msgs/Odometry to TF transforms. This can be useful
when playing back bag files for example.


## Topics

* `odom` (`nav_msgs/Odometry`) Input, subscribed to
* `/tf` Published to (using TF2)

## Parameters

* `~base_frame` (default: `base_footprint`) Child frame of published transform.
  Parent frame is copied from input message.
