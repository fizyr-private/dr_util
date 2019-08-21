// Catch
#include <catch2/catch.hpp>

// This repository
#include "expand.hpp"

namespace dr {

TEST_CASE("Expand -- simple", "simple") {
	REQUIRE(expandVariables("$test", {{"test", "foo"}})   == "foo");
	REQUIRE(expandVariables("$test", {{"test", "bar"}})   == "bar");
	REQUIRE(expandVariables("${test}", {{"test", "foo"}}) == "foo");
	REQUIRE(expandVariables("${test}", {{"test", "bar"}}) == "bar");
}

TEST_CASE("Expand -- sentence", "sentence") {
	REQUIRE(expandVariables("Hello $name, welcome to $place", {{"name", "Rick"}, {"place", "Earth"}})     == "Hello Rick, welcome to Earth");
	REQUIRE(expandVariables("Hello ${name}, welcome to ${place}", {{"name", "Rick"}, {"place", "Earth"}}) == "Hello Rick, welcome to Earth");
}

TEST_CASE("Expand -- nipple_brackets", "nipple_brackets") {
	REQUIRE(expandVariables("test$testtest", {{"test", "wrong"}, {"testtest", "good"}})   == "testgood");
	REQUIRE(expandVariables("test${test}test", {{"test", "good"}, {"testtest", "wrong"}}) == "testgoodtest");
}

TEST_CASE("Expand -- ignore_empty_key", "ignore_empty_key") {
	REQUIRE(expandVariables("$", {{"", "aap"}})   == "$");
	REQUIRE(expandVariables("${}", {{"", "aap"}}) == "${}");
}

}
