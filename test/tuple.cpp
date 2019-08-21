// C++
#include <string>
#include <sstream>
#include <array>

// Catch
#include <catch2/catch.hpp>

// This repository
#include "tuple.hpp"

TEST_CASE("TupleTest -- sliceOne", "sliceOne") {
	auto tuple = std::make_tuple(1, true, 3);
	REQUIRE(1u   == std::tuple_size<decltype(dr::tuple_slice<0, 1>(tuple))>::value);
	REQUIRE(1u   == std::tuple_size<decltype(dr::tuple_slice<1, 1>(tuple))>::value);
	REQUIRE(1u   == std::tuple_size<decltype(dr::tuple_slice<2, 1>(tuple))>::value);
	REQUIRE(1    == std::get<0>(dr::tuple_slice<0, 1>(tuple)));
	REQUIRE(true == std::get<0>(dr::tuple_slice<1, 1>(tuple)));
	REQUIRE(3    == std::get<0>(dr::tuple_slice<2, 1>(tuple)));
}

TEST_CASE("TupleTest -- sliceTwo", "sliceTwo") {
	auto tuple = std::make_tuple(1, true, 3);
	REQUIRE(2u   == std::tuple_size<decltype(dr::tuple_slice<0, 2>(tuple))>::value);
	REQUIRE(2u   == std::tuple_size<decltype(dr::tuple_slice<1, 2>(tuple))>::value);
	REQUIRE(1    == std::get<0>(dr::tuple_slice<0, 2>(tuple)));
	REQUIRE(true == std::get<1>(dr::tuple_slice<0, 2>(tuple)));
	REQUIRE(true == std::get<0>(dr::tuple_slice<1, 2>(tuple)));
	REQUIRE(3    == std::get<1>(dr::tuple_slice<1, 2>(tuple)));
}

TEST_CASE("TupleTest -- sliceThree", "sliceThree") {
	auto tuple = std::make_tuple(1, true, 3);
	REQUIRE(3u   == std::tuple_size<decltype(dr::tuple_slice<0, 3>(tuple))>::value);
	REQUIRE(1    == std::get<0>(dr::tuple_slice<0, 3>(tuple)));
	REQUIRE(true == std::get<1>(dr::tuple_slice<0, 3>(tuple)));
	REQUIRE(3    == std::get<2>(dr::tuple_slice<0, 3>(tuple)));
}

TEST_CASE("TupleTest -- tail", "tail") {
	auto tuple = std::make_tuple(1, true, 3);
	REQUIRE(2u   == std::tuple_size<decltype(dr::tuple_tail(tuple))>::value);
	REQUIRE(true == std::get<0>(dr::tuple_tail(tuple)));
	REQUIRE(3    == std::get<1>(dr::tuple_tail(tuple)));
}

TEST_CASE("TupleTest -- tailEmpty", "tailEmpty") {
	auto tuple = std::make_tuple(1);
	REQUIRE(0u   == std::tuple_size<decltype(dr::tuple_tail(tuple))>::value);
}
