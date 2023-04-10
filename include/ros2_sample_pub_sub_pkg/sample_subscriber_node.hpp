#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#pragma once

class SampleSubscriberNode : public rclcpp::Node
{
private:
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_hello_world_;

public:
	SampleSubscriberNode();

private:
	void OnSubscribed_hello_world(const std_msgs::msg::String::SharedPtr hello_world);
};