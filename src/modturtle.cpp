/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2019 Akwasi A Obeng 
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

#include "modturtlebot.h"

TurtleBot::TurtleBot() {
  // Setup publisher to publish to advertise topic to move turtlebot
  pub = n.advertise <geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);

  // Setup subscriber to subscriber to scan obstacles
  sub = n.subscribe("/scan", 1000, &TurtleBot::scanEnvCallBack, this);

  thresdist = 1.5;  // setting threshold distance
}

TurtleBot::~TurtleBot() {}

void TurtleBot::scanEnvCallBack(const sensor_msgs::LaserScan::ConstPtr& msg) {
  // loop through scan and check if range is below target
  // set obstacle to true to indicate there is an obstacle ahead
  for (int i = 0; i< msg->ranges.size(); ++i) {
    if (msg->ranges[i] < thresdist) {
       if (isnan(msg->ranges[i]))  // if values is NAN then turtlebot, then
                                  // turtlebot has collided with object
          ROS_ERROR_STREAM("TurtleBot Collided");
       obstacle = true;  // set to true to indicate obstacle ahead
       return;
    }
  }
  obstacle = false;  // set to false to indicate no obstacle
  return;
}



void TurtleBot::moveTurtleBot() {
  ros::Rate loop_rate(10);  // publish rate

  while (ros::ok()) {
    pub.publish(msg);  // publish message
    /* check if there is an  obstacle do the following
    *  Stop, Rotate about z axis, and then Move 
    */
    if (obstacle) {
      msg.linear.x = 0;  // Stop
      msg.angular.z = 1;  // Rotate about z axis

      // Set obstacle to false to indicate it is okay to move
      obstacle = false;
    } else {
      // Translate in x direction with no rotation
      msg.linear.x = 0.5;
      msg.angular.z = 0;
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
}


