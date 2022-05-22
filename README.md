# sim_ur5

publish joint angles as function of sine waves on joints of a ur5 robot simulated with gazebo.

### required

ROS melodic (Ubuntu 18.04)
gazebo

### Installation

In a catkin workspace :

If not installed already clone the universal robot package :
```
sudo apt-get install ros-melodic-universal-robot
```

and then this pacage :
```
git clone  AmbLeVif/sim_ur5

```

### Usage

compile with :
```
catkin_make
```

launch all the nodes with
```
roslaunch sim_ur5 full_sim1.launch
```

