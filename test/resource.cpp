// Catch2
#include <catch2/catch.hpp>

// ROS
#include <ros/package.h>

// This repository
#include "resource.hpp"

#include <iostream>

TEST_CASE("ResourceTest -- packageUrl", "packageUrl") {
	std::cout << "first:" << ros::package::getPath("dr_ros") << "\n";
	std::cout << "second:" << dr::resolveResourceUrl("package://dr_ros/test.file") << "\n";
	// REQUIRE(ros::package::getPath("dr_ros") + "/test.file" == dr::resolveResourceUrl("package://dr_ros/test.file"));
	SUCCEED();
}

TEST_CASE("ResourceTest -- localFileUrl", "localFileUrl") {
	REQUIRE("/test.file" == dr::resolveResourceUrl("file:///test.file"));
}

TEST_CASE("ResourceTest -- remoteFileUrl", "remoteFileUrl") {
	REQUIRE_THROWS(dr::resolveResourceUrl("file://host/test.file"));
}

TEST_CASE("ResourceTest -- unsupportedScheme", "unsupportedScheme") {
	REQUIRE_THROWS(dr::resolveResourceUrl("http://example.com/test.file"));
}
