#include "modturtlebot.h"

TurtleBot::TurtleBot() {
  pub = n.advertise <geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
  sub = n.subscribe("/scan",1000,&TurtleBot::scanEnvCallBack,this);
}

TurtleBot::~TurtleBot() {

}

void TurtleBot::scanEnvCallBack(const sensor_msgs::LaserScan::ConstPtr& msg) {
  for (int i = 0; i< msg->ranges.size(); ++i) {
    if (msg->ranges[i] < 1.5)
       obstacle = true;
       return;
  }
  obstacle = false;
  return;
}

void TurtleBot::moveTurtleBot() {
  ros::Rate loop_rate(10); 

  while (ros::ok()) {
    pub.publish(msg);

    //std_msgs::String m;
    //std::stringstream ss;

    if (obstacle) {
      msg.angular.z = 1;
      msg.linear.x = 0;

      obstacle = false;
    } else {
      msg.linear.x = 0.5;
      msg.angular.z = 0;
    }
   
    //m.data= ss.str();
    //ROS_INFO_STREAM(""<<m.data.c_str());

    //std::cout<< obstacle << std::endl;
    ros::spinOnce();

    loop_rate.sleep();
  }
}


