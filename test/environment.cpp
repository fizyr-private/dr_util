// This repository
#include "environment.hpp"

// Catch
#include <catch2/catch.hpp>

// C
#include <stdlib.h>

namespace dr {

TEST_CASE("Environment -- getEnvironment", "getEnvironment") {
	::clearenv();
	REQUIRE(getEnvironment() == (std::map<std::string, std::string>{}));

	::setenv("FOO", "aap", true);
	REQUIRE(getEnvironment() == (std::map<std::string, std::string>{{"FOO", "aap"}}));
	
	::setenv("BAR", "noot", true);
	REQUIRE(getEnvironment() == (std::map<std::string, std::string>{{"FOO", "aap"}, {"BAR", "noot"}}));
}

}
