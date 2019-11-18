#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <ros/ros.h>
#include <sstream>
#include <iostream>
#include <std_msgs/String.h>

class TurtleBot {
 private:
   ros::NodeHandle n;
   ros::Publisher pub;
   ros::Subscriber sub;
   geometry_msgs::Twist msg;
   bool obstacle;
   void scanEnvCallBack(const sensor_msgs::LaserScan::ConstPtr& msg);


 public:
    TurtleBot();
    ~TurtleBot();
    void moveTurtleBot();

};
