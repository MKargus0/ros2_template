cmake_minimum_required(VERSION 3.5)
project(ros2_template)

#Default to C++17
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# library type check
if(DEFINED ${PROJECT_NAME}_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ${${PROJECT_NAME}_SHARED_LIBS})
endif()

# Build type settings check
if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT DEFINED CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

########################
# Project dependencies #
########################

find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

###################
# Project sources #
###################

add_subdirectory(src/nodes)


##################
# Project target #
##################

# link library dependencies
target_link_libraries(${PROJECT_NAME} ${rclcpp_LIBRARIES})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
        "$<BUILD_INTERFACE:${rclcpp_INCLUDE_DIRS}>"
        )

# add executables
add_executable(talker src/executables/talker.cpp)
target_link_libraries(talker ${PROJECT_NAME})
# ros2 dependencies
ament_target_dependencies(talker
        rclcpp
        std_msgs)

# install nodes executables
install(TARGETS
        talker
        DESTINATION lib/${PROJECT_NAME})

# install launch files
install(DIRECTORY
        launch
        DESTINATION share/${PROJECT_NAME}/
        )

ament_package()