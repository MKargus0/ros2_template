from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            namespace= "ros2_template1", package='ros2_template', executable='talker', output='screen'),
    ])