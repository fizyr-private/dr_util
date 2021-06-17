// This repository
#include "resource.hpp"

// Catch2
#include <catch2/catch.hpp>

// ROS
#include <ros/package.h>

TEST_CASE("ResourceTest") {
	
	SECTION("packageUrl") {
		/**
		 * TODO: This test fails in BuildBot because it can not resolve the location
		 *       of the "package://some_package". At the end of a chain of calls,
		 *       'ROSPack::run(..)' excecutes "rospack find some_package".
		 * 
		 *       More about this method.
		 *       http://docs.ros.org/indigo/api/rospack/html/rospack__backcompat_8cpp_source.html		 * 
		 * 
		 *       This method succeeds if rospack is installed and located in the PATH.
		 *       In BuildBot test-container rospack is installed, but its location is not in the PATH.
		 **/
		REQUIRE(ros::package::getPath("dr_util") + "/test.file" == dr::resolveResourceUrl("package://dr_util/test.file"));
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
