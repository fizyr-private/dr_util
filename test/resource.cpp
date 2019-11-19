// This repository
#include "resource.hpp"

// Catch2
#include <catch2/catch.hpp>

// ROS
#include <ros/package.h>

// C++
#include <iostream>
#include <exception>

namespace {

	std::string exec(const char * cmd) {
		std::array<char, 128> buffer;
		std::string result;
		std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
		if (!pipe) {
			throw std::runtime_error("popen() failed!");
		}
		while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
			result += buffer.data();
		}
		return result;
	}
}


TEST_CASE("ResourceTest") {
	
	SECTION("packageUrl") {

		std::cout << "find result:" << exec("find / -name rospack") << "\n";
		std::cout << "value of PATH:" << exec("echo $PATH") << "\n";

		// std::string first = ros::package::getPath("dr_ros") + "/test.file" ;
		std::string first = ros::package::getPath("dr_log") + "/test.file" ;
		// std::string second = dr::resolveResourceUrl("package://dr_ros/test.file");

		std::string second;

		try {
			// second = dr::resolveResourceUrl("package://dr_log/test.file");
			second = dr::resolveResourceUrl("anything://dr_log/test.file");
		} catch (std::exception & e){
			std::cout << "exception:" << e.what() << "\n";
		}
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
