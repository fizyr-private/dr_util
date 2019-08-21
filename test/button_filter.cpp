// Catch
#include <catch2/catch.hpp>

// This repository
#include "button_filter.hpp"

namespace dr {

TEST_CASE("ButtonFilterTest -- filterAlwaysHigh", "filterAlwaysHigh") {
	ButtonFilter bf(true, false);

	// pass through high signals always
	REQUIRE(bf.filter(false) == false);
	REQUIRE(bf.filter(true)  == true);
	REQUIRE(bf.filter(true)  == true);
}

TEST_CASE("ButtonFilterTest -- filterAlwaysLow", "filterAlwaysLow") {
	ButtonFilter bf(false, true);

	// pass through low signals always
	REQUIRE(bf.filter(false) == true);
	REQUIRE(bf.filter(true)  == true);
	REQUIRE(bf.filter(true)  == false);
}

TEST_CASE("ButtonFilterTest -- filterAlwaysHighAndLow", "filterAlwaysHighAndLow") {
	ButtonFilter bf(true, true);

	// pass through any signal
	REQUIRE(bf.filter(false) == true);
	REQUIRE(bf.filter(false) == true);
	REQUIRE(bf.filter(true)  == true);
	REQUIRE(bf.filter(true)  == true);
}

TEST_CASE("ButtonFilterTest -- filterRisingEdge", "filterRisingEdge") {
	ButtonFilter bf;

	// test rising edge
	REQUIRE(bf.filter(false) == false);
	REQUIRE(bf.filter(true)  == true);
}

TEST_CASE("ButtonFilterTest -- filterFallingEdge", "filterFallingEdge") {
	ButtonFilter bf;

	// test falling edge
	REQUIRE(bf.filter(true)  == true);
	REQUIRE(bf.filter(false) == true);
}

TEST_CASE("ButtonFilterTest -- filterMultiple", "filterMultiple") {
	ButtonFilter bf;

	// test multiple signals
	REQUIRE(bf.filter(true) == true);
	REQUIRE(bf.filter(true) == false);

	REQUIRE(bf.filter(false) == true);
	REQUIRE(bf.filter(false) == false);

	REQUIRE(bf.filter(true) == true);
	REQUIRE(bf.filter(true) == false);
}

}
