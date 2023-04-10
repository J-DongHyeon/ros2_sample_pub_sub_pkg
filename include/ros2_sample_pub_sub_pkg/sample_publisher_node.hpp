#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#pragma once


class SamplePublisherNode : public rclcpp::Node
{
private:
	size_t count_;
	rclcpp::TimerBase::SharedPtr timer_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_hello_world_;

public:
	SamplePublisherNode();

private:
	void OnTimerElapsed();
};