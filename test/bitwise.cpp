// This repository
#include "bitwise.hpp"

// Catch
#include <catch2/catch.hpp>

namespace dr {

TEST_CASE("BitwiseTest") {

	SECTION("makeBitMask") {
		// least significant bit
		REQUIRE(       0x1u == bitMask(0));

		// some middle bit
		REQUIRE(    0x4000u == bitMask(14));

		// most significant bit
		REQUIRE(0x80000000u == bitMask(31));
	}

	SECTION("testTestBit") {
		// least significant bit
		REQUIRE(testBit(0x1, 0)  == true);
		REQUIRE(testBit(0x1, 14) == false);
		REQUIRE(testBit(0x1, 31) == false);

		// some middle bit
		REQUIRE(testBit(0x4000, 0)  == false);
		REQUIRE(testBit(0x4000, 14) == true);
		REQUIRE(testBit(0x4000, 31) == false);

		// most significant bit
		REQUIRE(testBit(0x80000000, 0)  == false);
		REQUIRE(testBit(0x80000000, 14) == false);
		REQUIRE(testBit(0x80000000, 31) == true);

		// no value
		REQUIRE(testBit(0, 0)  == false);
		REQUIRE(testBit(0, 14) == false);
		REQUIRE(testBit(0, 31) == false);

		// all bits set to true
		REQUIRE(testBit(0xFFFFFFFF, 0)  == true);
		REQUIRE(testBit(0xFFFFFFFF, 14) == true);
		REQUIRE(testBit(0xFFFFFFFF, 31) == true);
	}

	SECTION("testTestRising") {
		// no change for all bits set to 1
		REQUIRE(testRising(0xFFFFFFFF, 0xFFFFFFFF, 0)  == false);
		REQUIRE(testRising(0xFFFFFFFF, 0xFFFFFFFF, 14) == false);
		REQUIRE(testRising(0xFFFFFFFF, 0xFFFFFFFF, 31) == false);

		// no change for all bits set to 0
		REQUIRE(testRising(0, 0, 0)  == false);
		REQUIRE(testRising(0, 0, 14) == false);
		REQUIRE(testRising(0, 0, 31) == false);

		// ignore falling value
		REQUIRE(testRising(0xFFFFFFFF, 0, 0)  == true);
		REQUIRE(testRising(0xFFFFFFFF, 0, 14) == true);
		REQUIRE(testRising(0xFFFFFFFF, 0, 31) == true);

		// test rising edge
		REQUIRE(testRising(0, 0xFFFFFFFF, 0)  == false);
		REQUIRE(testRising(0, 0xFFFFFFFF, 14) == false);
		REQUIRE(testRising(0, 0xFFFFFFFF, 31) == false);

		// test specific rising edge
		REQUIRE(testRising(0x1, 0, 0)         == true);
		REQUIRE(testRising(0x4000, 0, 14)     == true);
		REQUIRE(testRising(0x80000000, 0, 31) == true);

		// test wrong rising edge
		REQUIRE(testRising(0x2, 0, 0)         == false);
		REQUIRE(testRising(0x8000, 0, 14)     == false);
		REQUIRE(testRising(0x40000000, 0, 31) == false);
	}
}

}
