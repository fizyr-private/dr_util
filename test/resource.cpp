// This repository
#include "resource.hpp"

// Catch2
#include <catch2/catch.hpp>

// ROS
#include <ros/package.h>

// C++
#include <iostream>

TEST_CASE("ResourceTest") {
	
	SECTION("packageUrl") {
		// std::string first = ros::package::getPath("dr_ros") + "/test.file" ;
		std::string first = ros::package::getPath("dr_log") + "/test.file" ;
		// std::string second = dr::resolveResourceUrl("package://dr_ros/test.file");
		std::string second = dr::resolveResourceUrl("package://dr_log/test.file");
		// std::string second = dr::resolveResourceUrl("package://boost/test.file");

		std::cout << "first:" << first << "\n";
		std::cout << "second:" << second << "\n";

		REQUIRE(first == second);
	}

	SECTION("localFileUrl") {
		REQUIRE("/test.file" == dr::resolveResourceUrl("file:///test.file"));
	}

	SECTION("remoteFileUrl") {
		REQUIRE_THROWS(dr::resolveResourceUrl("file://host/test.file"));
	}

	SECTION("unsupportedScheme") {
		REQUIRE_THROWS(dr::resolveResourceUrl("http://example.com/test.file"));
	}
}
