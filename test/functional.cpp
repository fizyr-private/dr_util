// C++
#include <string>
#include <sstream>
#include <array>

// Catch
#include <catch2/catch.hpp>

// This repository
#include "functional.hpp"
#include "tuple.hpp"

TEST_CASE("FunctionalTest -- callHardcoded", "callHardcoded") {
	REQUIRE(true  == dr::call([] () { return true;  }, std::make_tuple()));
	REQUIRE(false == dr::call([] () { return false; }, std::make_tuple()));
}

TEST_CASE("FunctionalTest -- callInput", "callInput") {
	REQUIRE(true  == dr::call([] (bool input) { return input; }, std::make_tuple(true)));
	REQUIRE(false == dr::call([] (bool input) { return input; }, std::make_tuple(false)));
}

TEST_CASE("FunctionalTest -- callSum", "callSum") {
	REQUIRE( 3 == dr::call([] (int a, int b) { return a + b; }, std::make_tuple(1, 2)));
	REQUIRE(17 == dr::call([] (int a, int b) { return a + b; }, std::make_tuple(7, 10)));
}
