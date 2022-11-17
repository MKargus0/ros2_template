//
// Created by regislab on 18.11.22.
//

#ifndef VSLAM_SRC_NODES_PUBLISHER_MINIMALPUBLISHER_HPP_
#define VSLAM_SRC_NODES_PUBLISHER_MINIMALPUBLISHER_HPP_

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
	public:
		MinimalPublisher();

	private:
		void timer_callback();
		rclcpp::TimerBase::SharedPtr timer_;
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
		size_t count_;
};

#endif //VSLAM_SRC_NODES_PUBLISHER_MINIMALPUBLISHER_HPP_
