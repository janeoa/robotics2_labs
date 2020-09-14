#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <math.h>

int main(int argc, char **argv){

    ros::init(argc, argv, "rotate");
    ros::NodeHandle nh;
    ros::Publisher pub3 = nh.advertise<std_msgs::Float64>("/robot/joint1_position_controller/command", 100);
    float loopRate = 10;
    ros::Rate loop_rate(loopRate);
    ros::Time startTime = ros::Time::now();
    long loopCount = 0;


    while (ros::ok()){
        std_msgs::Float64 msg_to_send;

        loopCount++;

        msg_to_send.data = sin(loopCount/loopRate/1.7);
   
        pub3.publish(msg_to_send);

        char theLog[80];
        sprintf(theLog, "Sine loop cound: %ld", loopCount);
        ROS_INFO(theLog);

        ros::spinOnce();
        loop_rate.sleep();
    }

}