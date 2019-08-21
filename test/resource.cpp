// Catch2
#include <catch2/catch.hpp>

// ROS
#include <ros/package.h>

// This repository
#include "resource.hpp"

TEST_CASE("ResourceTest -- packageUrl", "packageUrl") {
	REQUIRE(ros::package::getPath("dr_util") + "/test.file" == dr::resolveResourceUrl("package://dr_util/test.file"));
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
