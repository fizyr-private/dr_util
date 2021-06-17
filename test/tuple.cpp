// This repository
#include "tuple.hpp"

// Catch
#include <catch2/catch.hpp>

// C++
#include <string>
#include <sstream>
#include <array>

TEST_CASE("TupleTest") {

	SECTION("sliceOne") {
		auto tuple = std::make_tuple(1, true, 3);
		REQUIRE(1u   == std::tuple_size<decltype(dr::tuple_slice<0, 1>(tuple))>::value);
		REQUIRE(1u   == std::tuple_size<decltype(dr::tuple_slice<1, 1>(tuple))>::value);
		REQUIRE(1u   == std::tuple_size<decltype(dr::tuple_slice<2, 1>(tuple))>::value);
		REQUIRE(1    == std::get<0>(dr::tuple_slice<0, 1>(tuple)));
		REQUIRE(true == std::get<0>(dr::tuple_slice<1, 1>(tuple)));
		REQUIRE(3    == std::get<0>(dr::tuple_slice<2, 1>(tuple)));
	}

	SECTION("sliceTwo") {
		auto tuple = std::make_tuple(1, true, 3);
		REQUIRE(2u   == std::tuple_size<decltype(dr::tuple_slice<0, 2>(tuple))>::value);
		REQUIRE(2u   == std::tuple_size<decltype(dr::tuple_slice<1, 2>(tuple))>::value);
		REQUIRE(1    == std::get<0>(dr::tuple_slice<0, 2>(tuple)));
		REQUIRE(true == std::get<1>(dr::tuple_slice<0, 2>(tuple)));
		REQUIRE(true == std::get<0>(dr::tuple_slice<1, 2>(tuple)));
		REQUIRE(3    == std::get<1>(dr::tuple_slice<1, 2>(tuple)));
	}

	SECTION("sliceThree") {
		auto tuple = std::make_tuple(1, true, 3);
		REQUIRE(3u   == std::tuple_size<decltype(dr::tuple_slice<0, 3>(tuple))>::value);
		REQUIRE(1    == std::get<0>(dr::tuple_slice<0, 3>(tuple)));
		REQUIRE(true == std::get<1>(dr::tuple_slice<0, 3>(tuple)));
		REQUIRE(3    == std::get<2>(dr::tuple_slice<0, 3>(tuple)));
	}

	SECTION("tail") {
		auto tuple = std::make_tuple(1, true, 3);
		REQUIRE(2u   == std::tuple_size<decltype(dr::tuple_tail(tuple))>::value);
		REQUIRE(true == std::get<0>(dr::tuple_tail(tuple)));
		REQUIRE(3    == std::get<1>(dr::tuple_tail(tuple)));
	}

	SECTION("tailEmpty") {
		auto tuple = std::make_tuple(1);
		REQUIRE(0u   == std::tuple_size<decltype(dr::tuple_tail(tuple))>::value);
	}
}