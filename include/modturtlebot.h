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

/**
 * @file Robot.cpp
 *
 * @author  Akwasi A Obeng(Navigator)
 *
 * @brief This program allows the turtlebot to sense and avoid 
 *        obstacles
 *
 * @version 1
 *
 * @date 2019-18-12
 *
 * This .h file has declarations for the class attributes and methods for
 * simple functionality of the sensing and avoiding obstacles for turtebot.
 */

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <ros/ros.h>
#include <sstream>
#include <iostream>
#include <std_msgs/String.h>
#include <math.h>

class TurtleBot {
 private:
  ros::NodeHandle n; // Sets up the node

  ros::Publisher pub; // Needed to publish to topics

  ros::Subscriber sub; // Needed to subcribe to topics

  geometry_msgs::Twist msg; // linear and angular velocities
                            // Needed to move turtlebot
  bool obstacle; // Flag to check whether object is near obstacle
  float thresdist; // Threshold distance for obstacles

    /**
     * @brief Callback method after subscribing to callback message 
     *        Scans envirnoment and checks it turtlebot is near to
     *        wall 
     *
     * @param A pointer with reference to subsrcibed messages
     * 
     * @return None
     *
     */
  void scanEnvCallBack(const sensor_msgs::LaserScan::ConstPtr& msg);


 public:
    /**
     * @brief Constructor to set initial values
     * 
     * @param None
     * 
     * @return None
     *
     */
    TurtleBot();

    /**
     * @brief Destructor to destroy turtebot object
     * 
     * @param None
     * 
     * @return None
     *
     */
    ~TurtleBot();
    /**
     * @brief method moves the turtlebot and avoids obstacles
     * 
     * @param None
     * 
     * @return None
     *
     */
    void moveTurtleBot();
};
