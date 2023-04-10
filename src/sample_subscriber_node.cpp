#include "ros2_sample_pub_sub_pkg/sample_subscriber_node.hpp"

#include <functional>
#include <memory>

SampleSubscriberNode::SampleSubscriberNode()
	:Node("sample_subscriber_node")
{
	auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
	sub_hello_world_ = this->create_subscription<std_msgs::msg::String>(
		"/helloworld",
		qos_profile,
		std::bind(&SampleSubscriberNode::OnSubscribed_hello_world, this, std::placeholders::_1));
}

void SampleSubscriberNode::OnSubscribed_hello_world(const std_msgs::msg::String::SharedPtr hello_world)
{
	RCLCPP_INFO(this->get_logger(), "Received message: '%s'", hello_world->data.c_str());
}


int main(int argc, char* argv[])
{
	rclcpp::init(argc, argv);
	auto node = std::make_shared<SampleSubscriberNode>();
	rclcpp::spin(node);
	rclcpp::shutdown();

	return 0;
}