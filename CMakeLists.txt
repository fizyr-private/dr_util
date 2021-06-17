cmake_minimum_required(VERSION 3.8)
project(dr_util)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)
add_link_options(LINKER:--as-needed)

find_package(catkin REQUIRED COMPONENTS
	dr_ros
	roslib
)

find_package(Boost REQUIRED COMPONENTS filesystem date_time)

include_directories("include/${PROJECT_NAME}")
include_directories(SYSTEM ${catkin_INCLUDE_DIRS})

catkin_package(
	LIBRARIES ${PROJECT_NAME}
	INCLUDE_DIRS include
	DEPENDS Boost
)

add_library(${PROJECT_NAME}
	src/environment.cpp
	src/expand.cpp
	src/file_system.cpp
	src/timestamp.cpp
	src/polynomial.cpp
)

target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${Boost_LIBRARIES})

if (CATKIN_ENABLE_TESTING)
	add_subdirectory(test)
endif()

install(
	TARGETS ${PROJECT_NAME}
	ARCHIVE DESTINATION "${CATKIN_PACKAGE_LIB_DESTINATION}"
	LIBRARY DESTINATION "${CATKIN_PACKAGE_LIB_DESTINATION}"
	RUNTIME DESTINATION "${CATKIN_PACKAGE_BIN_DESTINATION}"
	COMPONENT runtime
)

install(
	DIRECTORY "include/${PROJECT_NAME}/"
	DESTINATION "${CATKIN_PACKAGE_INCLUDE_DESTINATION}"
	COMPONENT development
)
