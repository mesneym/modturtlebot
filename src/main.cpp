#include "modturtlebot.h"

int main(int argc, char * argv[]) {
  ros::init(argc,argv,"modturtlebot");

  TurtleBot turtlebot;
  turtlebot.moveTurtleBot();

  return 0;
}
