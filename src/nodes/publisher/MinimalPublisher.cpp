#include "MinimalPublisher.hpp"

MinimalPublisher::MinimalPublisher()
	: Node("minimal_publisher"), count_(0)
{
	//	declare params
	declare_parameter("bot_name", ""); // defaults to ""
	declare_parameter("max_speed", 0.0); // defaults to 0.0
	// read parameters
	get_parameter("bot_name", bot_name_);
	get_parameter("max_speed", max_speed_);

	publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
	timer_ = this->create_wall_timer(
		500ms, std::bind(&MinimalPublisher::timer_callback, this));
}

void MinimalPublisher::timer_callback()
{
	auto message = std_msgs::msg::String();
	message.data = "Hello, world! " + bot_name_ + std::to_string(count_++);
	RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
	publisher_->publish(message);
}