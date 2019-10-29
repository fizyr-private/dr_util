// This repository
#include "expand.hpp"

// Catch
#include <catch2/catch.hpp>

namespace dr {

TEST_CASE("Expand") {

	SECTION("simple") {
		REQUIRE(expandVariables("$test", {{"test", "foo"}})   == "foo");
		REQUIRE(expandVariables("$test", {{"test", "bar"}})   == "bar");
		REQUIRE(expandVariables("${test}", {{"test", "foo"}}) == "foo");
		REQUIRE(expandVariables("${test}", {{"test", "bar"}}) == "bar");
	}

	SECTION("sentence") {
		REQUIRE(expandVariables("Hello $name, welcome to $place", {{"name", "Rick"}, {"place", "Earth"}})     == "Hello Rick, welcome to Earth");
		REQUIRE(expandVariables("Hello ${name}, welcome to ${place}", {{"name", "Rick"}, {"place", "Earth"}}) == "Hello Rick, welcome to Earth");
	}

	SECTION("nipple_brackets") {
		REQUIRE(expandVariables("test$testtest", {{"test", "wrong"}, {"testtest", "good"}})   == "testgood");
		REQUIRE(expandVariables("test${test}test", {{"test", "good"}, {"testtest", "wrong"}}) == "testgoodtest");
	}

	SECTION("ignore_empty_key") {
		REQUIRE(expandVariables("$", {{"", "aap"}})   == "$");
		REQUIRE(expandVariables("${}", {{"", "aap"}}) == "${}");
	}
}

}
