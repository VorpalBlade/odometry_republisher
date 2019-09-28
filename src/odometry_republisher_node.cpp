#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <nav_msgs/Odometry.h>
#include <tf2_ros/transform_broadcaster.h>

namespace odometry_republisher {

class Node
{
public:
  Node() {
    ros::NodeHandle nh_priv("~");

    nh_priv.param<std::string>("base_frame", base_frame, "base_footprint");

    odom_sub = nh.subscribe("odom", 10, &Node::odom_callback, this);
  }

private:
  //! Global node handle
  ros::NodeHandle nh;

  //! Publishes odometry transform.
  tf2_ros::TransformBroadcaster transform_broadcaster;

  //! Odometry subscription
  ros::Subscriber odom_sub;

  //! Child frame to publish
  std::string base_frame;

  //! Callback for ROS laser scan message
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg)
  {
    geometry_msgs::TransformStamped transform;

    transform.header.stamp = msg->header.stamp;
    transform.header.frame_id = msg->header.frame_id;

    transform.child_frame_id = base_frame;
    transform.transform.translation.x = msg->pose.pose.position.x;
    transform.transform.translation.y = msg->pose.pose.position.y;
    transform.transform.translation.z = msg->pose.pose.position.z;

    transform.transform.rotation = msg->pose.pose.orientation;

    transform_broadcaster.sendTransform(transform);
  }
};

} // namespace odometry_republisher

//! Main entry point, duh
int main(int argc, char **argv)
{
  ros::init(argc, argv, "odometry_republisher");

  // Instantiate main class
  odometry_republisher::Node node;
  ros::spin();

  return 0;
}
