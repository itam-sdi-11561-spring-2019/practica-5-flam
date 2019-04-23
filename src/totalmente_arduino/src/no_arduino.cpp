#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>

#define RATE_HZ 2

using namespace std;
ros::Publisher pub;

void get_msg(const std_msgs::String& msg) {
        string m = msg.data;
        ROS_INFO_STREAM("Respuesta de Arduino: " + m);
}

int main(int argc, char **argv){
        ros::init(argc,argv,"arduino_pub_node");
        ros::NodeHandle nh;
        ROS_INFO_STREAM("Inicializando publisher");                                                                                                                                                                                                                                                                 
        ROS_INFO_STREAM(ros::this_node::getName());

        ros::Publisher pub = nh.advertise<std_msgs::String> ("/other_msg", 1);
        ros::Subscriber sub_vel = nh.subscribe("/arduino_msg", 1000, &get_msg);
        ros::Rate rate(RATE_HZ);

        std_msgs::String msg;
	string msg_str;

        while (ros::ok()){
		cout << "Introduce un mensaje:" << endl;
                cin >> msg_str;

                msg.data = msg_str;
                pub.publish(msg);
                ros::spinOnce();
                rate.sleep();
        }
}

