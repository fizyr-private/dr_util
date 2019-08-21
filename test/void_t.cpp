// Catch
#include <catch2/catch.hpp>

// This repository
#include "void_t.hpp"

TEST_CASE("VoidT -- type", "type") {
	static_assert(std::is_same<void, dr::void_t<>>{}, "");
	static_assert(std::is_same<void, dr::void_t<int>>{}, "");
	static_assert(std::is_same<void, dr::void_t<bool>>{}, "");
	static_assert(std::is_same<void, dr::void_t<bool, int>>{}, "");
	SUCCEED();
}
