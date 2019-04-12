#include <ros/ros.h>

#include <iostream>
#include <geometry_msgs/Twist.h>
#define RATE_HZ 2


using namespace std;
string str;

int main(int argc, char **argv)
{
	ros::init(argc,argv,"turtle_controller_node");
	ros::NodeHandle nh;
	ROS_INFO_STREAM("turtle_controller_node initialized");																																							
	ROS_INFO_STREAM(ros::this_node::getName());
	ros::Rate rate(RATE_HZ);


	ros::Publisher pub = nh.advertise<geometry_msgs::Twist> ("/turtle1/cmd_vel", 1);
	geometry_msgs::Twist msg;	
	while (ros::ok())
	{
		cout << "Introduce un comando:" << endl;
		cin >> str;
		for(char& c : str){
			if(c == 0x32){
				msg.linear.x = 0;
				msg.angular.z = -1;
				pub.publish(msg);
			}else if(c == 0x34){
				msg.linear.x = -1;
				msg.angular.z = 0;
				pub.publish(msg);
			}else if(c == 0x36){
				msg.linear.x = 1;
				msg.angular.z = 0;
				pub.publish(msg);
			}else if(c == 0x38){
				msg.linear.x = 0;
				msg.angular.z = 1;
				pub.publish(msg);
			}
			ROS_INFO_STREAM(c);
			rate.sleep();

		}
		
		
	}

    return 0;
}
