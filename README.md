# sim_ur5

publish joint angles as function of sine waves on joints of a ur5 robot simulated with gazebo.

### required

ROS melodic (Ubuntu 18.04)

gazebo

### Installation

In a catkin workspace :
```
cd ~/catkin_ws/src
```

If not installed already clone the universal robot package :
```
git clone -b melodic-devel https://github.com/ros-industrial/universal_robot.git
```

and then this pacage :
```
git clone  AmbLeVif/sim_ur5

```

### Usage

compile with :
```
cd ~/catkin_ws
catkin_make
```

launch all the nodes with
```
roslaunch sim_ur5 full_sim1.launch
```

