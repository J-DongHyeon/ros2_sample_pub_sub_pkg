#include "ros2_sample_pub_sub_pkg/sample_publisher_node.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <string>



SamplePublisherNode::SamplePublisherNode()
	: Node("sample_publisher_node")
	, count_(0)
{
	auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
	pub_hello_world_ = this->create_publisher<std_msgs::msg::String>(
		"/helloworld"
		, qos_profile);

	timer_ = this->create_wall_timer(
		std::chrono_literals::1s,
		std::bind(&SamplePublisherNode::OnTimerElapsed, this));
}

void SamplePublisherNode::OnTimerElapsed()
{
	auto message = std_msgs::msg::String();
	message.data = "Hello World: " + std::to_string(count_++);
	RCLCPP_INFO(this->get_logger(), "Published message: '%s'", message.data.c_str());
	pub_hello_world_->publish(message);
}

int main(int argc, char* argv[])
{
	rclcpp::init(argc, argv);
	auto node = std::make_shared<SamplePublisherNode>();
	rclcpp::spin(node);
	rclcpp::shutdown();

	return 0;
}