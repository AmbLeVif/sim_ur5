#include <trajectory_msgs/JointTrajectory.h>
#include <cmath>
#include <ros/ros.h>

using namespace trajectory_msgs;
ros::Time startTime;

float sin_func()
{
  return sin((ros::Time::now() - startTime).toSec());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "sim1", ros::init_options::AnonymousName);
  ros::NodeHandle* n = new ros::NodeHandle;
  ros::Publisher joint_angle = n->advertise<JointTrajectory>("/arm_controller/command", 10);
  ros::Rate loop_rate(1);
  startTime = ros::Time::now();

  JointTrajectory traj;
  trajectory_msgs::JointTrajectoryPoint points_n;

  traj.header.frame_id = "base_link";
  traj.joint_names.resize(6);
  traj.points.resize(1);
  traj.points[0].positions.resize(6);

  traj.joint_names[0] ="shoulder_pan_joint";
  traj.joint_names[1] ="shoulder_lift_joint";
  traj.joint_names[2] ="elbow_joint";
  traj.joint_names[3] ="wrist_1_joint";
  traj.joint_names[4] ="wrist_2_joint";
  traj.joint_names[5] ="wrist_3_joint";

  while (ros::ok()) {

    traj.header.stamp = ros::Time::now();

    double s = sin_func();

     traj.points[0].positions[0] = s;
     traj.points[0].positions[1] = -1-s;
     traj.points[0].positions[2] = s;
     traj.points[0].positions[3] = s;
     traj.points[0].positions[4] = s;
     traj.points[0].positions[5] = s;
     traj.points[0].time_from_start = ros::Duration(1);
     joint_angle.publish(traj);
     ros::spinOnce();
 }
return 0;
}
