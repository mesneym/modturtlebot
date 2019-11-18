
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
   bool collision;


 public:
    TurtleBot();
    ~TurtleBot();
    void moveTurtleBot();
    void scanEnvCallBack(const sensor_msgs::LaserScan::ConstPtr& msg);

};

TurtleBot::TurtleBot() {
  pub = n.advertise <geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
  sub = n.subscribe("/scan",1000,&TurtleBot::scanEnvCallBack,this);
}

TurtleBot::~TurtleBot() {

}

void TurtleBot::scanEnvCallBack(const sensor_msgs::LaserScan::ConstPtr& msg) {
  for (int i = 0; i< msg->ranges.size(); ++i) {
    if (msg->ranges[i] < 0.5)
       collision = true;
       return;
  }

  collision = false;
  return;
}

void TurtleBot::moveTurtleBot() {
  ros::Rate loop_rate(10); 

  while (ros::ok()) {
    msg.linear.x = 1;
    //msg.angular.z = 1;
    pub.publish(msg);

    std_msgs::String m;
    std::stringstream ss;

    if (collision)
      ss << "Collision occured";
    else 
      ss << "collision never occured";
   
    m.data= ss.str();
    ROS_INFO_STREAM(""<<m.data.c_str());

    std::cout<< collision << std::endl;
    ros::spinOnce();

    loop_rate.sleep();
  }
}


int main(int argc, char * argv[]) {
  ros::init(argc,argv,"modturtlebot");

  TurtleBot turtlebot;
  turtlebot.moveTurtleBot();
  return 0;
}
