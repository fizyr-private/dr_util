#pragma once

#include <stdint.h>

namespace dr {
	/// Get the bitmask for a single bit.
	constexpr uint32_t bitMask(
		unsigned int bit ///< The index of the bit to generate the mask for, where 0 is the least significant bit.
	) {
		return 1 << bit;
	}

	/// Test the value of a specific bit in an integer.
	constexpr bool testBit(
		uint32_t value,  ///< The value to test.
		unsigned int bit ///< The index of the bit to test, where 0 is the least significant bit.
	) {
		return value & bitMask(bit);
	}

	/// Test for a newly high value of a specific bit.
	constexpr bool testRising(
		uint32_t value,  ///< The new value to test.
		uint32_t old,    ///< The old value.
		unsigned int bit ///< The index of the bit to test, where 0 is the least significant bit.
	) {
		return (value & bitMask(bit)) && !(old & bitMask(bit));
	}
}
