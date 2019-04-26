#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher pub("arduino_msg", &str_msg);

int LED = 13;

void message_ros(const std_msgs::String& ros_msg){
  String string_variable = ros_msg.data;
  digitalWrite(LED,HIGH);
  delay(3000);
  digitalWrite(LED,LOW);
  
  str_msg.data = "hola :)";
  pub.publish( &str_msg);
  
}

ros::Subscriber<std_msgs::String> sub("other_msg",&message_ros);

void setup(){
  nh.initNode();
  nh.advertise(pub);
  pinMode(LED, OUTPUT);
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
}
