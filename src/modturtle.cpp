
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sstream>

class modturtle {
 private:
   ros::NodeHandle n;
   ros::Publisher pub;
   geometry_msgs::Twist msg;

 public:
    modturtle();
    ~modturtle();
    void moveturtle();
};

modturtle::modturtle() {
  pub = n.advertise <geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
}

modturtle::~modturtle() {

}

void modturtle::moveturtle() {
  ros::Rate loop_rate(10); 
  while (ros::ok()) {
    msg.linear.x = 1;
    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }
}


int main(int argc, char * argv[]) {
  ros::init(argc,argv,"modturtlebot");
   
  modturtle turtlebot;

  turtlebot.moveturtle();
  return 0;
}
