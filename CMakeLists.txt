cmake_minimum_required(VERSION 3.0.2)
project(sim_ur5)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11 -fPIC -Wall -Wextra -lstdc++fs)

set(CMAKE_AUTOUIC ON)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  trajectory_msgs
  moveit_ros_planning_interface
)

#add_message_files(DIRECTORY msg FILES Num.msg)
#add_service_files(DIRECTORY srv FILES AddTwoInts.srv)

generate_messages(DEPENDENCIES std_msgs)

catkin_package()

include_directories( ${catkin_INCLUDE_DIRS})
set(CMAKE_AUTOMOC ON)

add_executable(sim1 src/sim1.cpp)
target_link_libraries(sim1 ${catkin_LIBRARIES})
