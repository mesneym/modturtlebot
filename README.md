# Navigating Obstacles with Turtlebot
This ROS package modifies the turtlebot package to move, sense and  avoid obstacles. The turtlebot  
scans for obstacles in its path and when an object is within some threshold range, the turtlebot adjust   
its direction to avoid collision.

### Dependencies
The package assumes that **ROS Kinetic** is installed.  
Cmake minimum version - 2.8.3   
Gazebo 
Turtlebot package


### Build the project

```
mkdir ~/catkin_ws/src
cd ~/catkin_ws/src
git clone 'https://github.com/mesneym/modturtlebot.git'
cd  ~/catkin_ws 
catkin_make
```
#### Add package to ROS workspace
```
. ~/catkin_ws/devel/setup.bash
```

### Run the Package with Roslaunch
Follow the instructions below to run the package.

```
cd ~/catkin_ws/
roslaunch modturtlebot modturtlebot.launch 
```

### Record and Play Topics
To record published messages and play them at a later time, create a new terminal, add   
package to workspace and follow the instructions below.
```
  cd ~/catkin_ws
  roslaunch beginner_tutorials beginner_tutorials.launch record:=true

```

Enter the command below to view information on the published messages recorded
```
  rosbag info record.bag
```

On a new terminal, enter the command below to play the record
```
rosbag play record.bag

```

To view already saved rosbag, click on [rosbag](https://drive.google.com/drive/folders/1iC0oEa_GIVzM2kWgU9rPxpvORKPewiUJ?usp=sharing)


