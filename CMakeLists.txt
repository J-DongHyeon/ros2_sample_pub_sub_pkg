cmake_minimum_required(VERSION 3.5)
project(ros2_sample_pub_sub_pkg)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 사용할 의존성 패키지들 find
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# 현재 패키지 내에서 #include 할 시, 'ros2_sample_pub_sub_pkg/include/' 경로를 자동으로 찾아가도록 한다.
include_directories(
  include
)

# 어떠한 소스코드를 build 하여 노드로 실행시킬 것인지 선언
# 하나의 노드에 여러 소스코드가 build 될 수 있다.
add_executable(sample_publisher_node
	src/sample_publisher_node.cpp
)

add_executable(sample_subscriber_node
	src/sample_subscriber_node.cpp
)

# target 노드가 어떠한 패키지들을 의존하는지 언급한다.
ament_target_dependencies(sample_publisher_node rclcpp std_msgs)

ament_target_dependencies(sample_subscriber_node rclcpp std_msgs)

# target 노드들을 install
install(TARGETS
	sample_publisher_node
	sample_subscriber_node
	DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
