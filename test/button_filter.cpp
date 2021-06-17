// This repository
#include "button_filter.hpp"

// Catch
#include <catch2/catch.hpp>

namespace dr {

TEST_CASE("ButtonFilterTest") {

	SECTION("filterAlwaysHigh") {
		ButtonFilter bf(true, false);

		// pass through high signals always
		REQUIRE(bf.filter(false) == false);
		REQUIRE(bf.filter(true)  == true);
		REQUIRE(bf.filter(true)  == true);
	}

	SECTION("filterAlwaysLow") {
		ButtonFilter bf(false, true);

		// pass through low signals always
		REQUIRE(bf.filter(false) == true);
		REQUIRE(bf.filter(true)  == true);
		REQUIRE(bf.filter(true)  == false);
	}

	SECTION("filterAlwaysHighAndLow") {
		ButtonFilter bf(true, true);

		// pass through any signal
		REQUIRE(bf.filter(false) == true);
		REQUIRE(bf.filter(false) == true);
		REQUIRE(bf.filter(true)  == true);
		REQUIRE(bf.filter(true)  == true);
	}

	SECTION("filterRisingEdge") {
		ButtonFilter bf;

		// test rising edge
		REQUIRE(bf.filter(false) == false);
		REQUIRE(bf.filter(true)  == true);
	}

	SECTION("filterFallingEdge") {
		ButtonFilter bf;

		// test falling edge
		REQUIRE(bf.filter(true)  == true);
		REQUIRE(bf.filter(false) == true);
	}

	SECTION("filterMultiple") {
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

}
