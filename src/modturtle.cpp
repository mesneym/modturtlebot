
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sstream>

class TurtleBot {
 private:
   ros::NodeHandle n;
   ros::Publisher pub;
   geometry_msgs::Twist msg;

 public:
    TurtleBot();
    ~TurtleBot();
    void moveTurtleBot();
    
};

TurtleBot::TurtleBot() {
  pub = n.advertise <geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
}

TurtleBot::~TurtleBot() {

}

void TurtleBot::moveTurtleBot() {
  ros::Rate loop_rate(10); 

  while (ros::ok()) {
    //msg.linear.x = 1;
    msg.linear.z = 1;
    //msg.angular.z = 1;
    pub.publish(msg);

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
