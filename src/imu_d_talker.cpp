#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Imu.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
  */
int main(int argc, char **argv)
{
   ros::init(argc, argv, "talker");


   ros::NodeHandle nh;

   ros::Publisher chatter_pub = nh.advertise<sensor_msgs::Imu>("imu/data", 1000);
   ros::Rate loop_rate(100);   //Hz

   int count = 0;
   while (ros::ok())
   {
      sensor_msgs::Imu imu_msg;

      imu_msg.header.stamp = ros::Time::now();
      imu_msg.header.frame_id = "/imu_link";

      std::stringstream ss;
      imu_msg.angular_velocity.x = 0;
      imu_msg.angular_velocity.y = 0;
      imu_msg.angular_velocity.z = 0;
      imu_msg.linear_acceleration.x = 0;
      imu_msg.linear_acceleration.y = 0;
      imu_msg.linear_acceleration.z = 9.80665;
      imu_msg.orientation.x = 0;
      imu_msg.orientation.y = 0;
      imu_msg.orientation.z = 0;
      imu_msg.orientation.w = 1;
      
      chatter_pub.publish(imu_msg);

      ros::spinOnce();

      loop_rate.sleep();
      ++count;
   }

   return 0;
}
