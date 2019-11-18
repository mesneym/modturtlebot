cmake_minimum_required(VERSION 2.8.3)
project(modturtlebot)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS 
             roscpp 
      			 rospy 
		      	 std_msgs 
             sensor_msgs
             genmsg
             message_generation
             tf)

 ## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()


## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(modturtlebot src/modturtle.cpp src/main.cpp)
target_link_libraries(modturtlebot ${catkin_LIBRARIES})
