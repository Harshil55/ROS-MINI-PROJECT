#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char **argv) {
//Initializes ROS, and sets up a node
ros::init(argc, argv, "random_husky_commands");
ros::NodeHandle nh;

//Ceates the publisher, and tells it to publish
///twist_marker_server/cmd_vel, with a queue size of 100
ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/twist_marker_server/cmd_vel", 100);

//Sets up the random number generator
srand(time(0));

//Sets the loop to publish at a rate of 10Hz
ros::Rate rate(10);

  while(ros::ok()) {
    //Declares the message to be sent
    geometry_msgs::Twist msg;
    //Set value x to 0.2
    msg.linear.x=0.2;
    //Set value y to 0
    msg.linear.y=0;
    //Set value z to 0
    msg.linear.z=0;
    
    // Set angular
    msg.angular.x=0;
    msg.angular.y=0;
    msg.angular.z=0;
    
    //Publish the message
    pub.publish(msg);

    //Delays until it is time to send another message
    rate.sleep();
    }
}
