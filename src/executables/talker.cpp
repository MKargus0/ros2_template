//
// Created by regislab on 17.11.22.
//
#include "MinimalPublisher.hpp"

int main(int argc, char * argv[])
{
	rclcpp::init(argc, argv);
	rclcpp::executors::MultiThreadedExecutor executor;
	auto node = std::make_shared<MinimalPublisher>();
	executor.add_node(node);
	executor.spin();
	rclcpp::shutdown();
	return 0;
}