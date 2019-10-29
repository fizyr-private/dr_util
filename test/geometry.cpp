// This repository
#include "geometry.hpp"

// Catch
#include <catch2/catch.hpp>

namespace {
	void requireEqual(float const & a, float const & b)	{
		REQUIRE_THAT(a, Catch::WithinULP(b, 0));
	}

	void requireNear(float const & a, float const & b, float const &tol) {
		float diff = std::abs(a - b);
		if (diff <= tol) {
			SUCCEED();
		} else {
			std::string msg = "first argument " + std::to_string(a) +
				" differs from the second argument " + std::to_string(b) +
				" in " + std::to_string(diff) +
				" which is larger than the allowed tolerance " + std::to_string(tol);
			FAIL(msg);
		}
	}
}


TEST_CASE("GeometryTest") {
	
	SECTION("testPi") {
		// test equality with C defined pi
		requireEqual(dr::pi(), M_PI);
	}

	SECTION("testDegrees") {
		// test normal use case
		requireEqual(dr::degrees(0),   0);
		requireEqual(dr::degrees(180), M_PI);
		requireEqual(dr::degrees(360), 2 * M_PI);
		requireNear(dr::degrees(37), 0.645771823237901, 0.0000001); // 37 / 180 * pi

		// test negativity
		requireEqual(dr::degrees(-180), -M_PI);
		requireEqual(dr::degrees(-360), -2 * M_PI);
	}

	SECTION("testToDegrees") {
		// test normal use case
		requireEqual(dr::to_degrees(0), 0);
		requireEqual(dr::to_degrees(M_PI), 180);
		requireEqual(dr::to_degrees(2 * M_PI), 360);
		requireNear(dr::to_degrees(0.645771823237901), 37, 0.0000001); // 37 / 180 * pi

		// test negativity
		requireEqual(dr::to_degrees(-M_PI), -180);
		requireEqual(dr::to_degrees(-2 * M_PI), -360);
	}

	SECTION("testSign") {
		// normal use cases
		REQUIRE(dr::sign(-1) == -1);
		REQUIRE(dr::sign(1)  ==  1);
		REQUIRE(dr::sign(0)  ==  0);

		// double use cases
		REQUIRE(dr::sign(M_PI)  == 1);
		REQUIRE(dr::sign(-M_PI) == -1);
		REQUIRE(dr::sign(std::numeric_limits<double>::quiet_NaN()) == 0);
	}

	SECTION("testNormalizeAngle") {
		// normal use
		requireEqual(dr::normalizeAngle(3 * M_PI), M_PI);
		requireEqual(dr::normalizeAngle(3.5 * M_PI), 1.5 * M_PI);

		// negativity
		requireEqual(dr::normalizeAngle(-3 * M_PI), M_PI);
		requireEqual(dr::normalizeAngle(-3.5 * M_PI), 0.5 * M_PI);
	}

	SECTION("testAngleFrom") {
		// same as normalizeAngle

		// normal use
		requireEqual(dr::angleFrom(3 * M_PI,   0), M_PI);
		requireEqual(dr::angleFrom(3.5 * M_PI, 0), 1.5 * M_PI);

		// negative angle
		requireEqual(dr::angleFrom(-3 * M_PI,   0), M_PI);
		requireEqual(dr::angleFrom(-3.5 * M_PI, 0), 0.5 * M_PI);

		// set different angle

		// normal use
		requireEqual(dr::angleFrom(3 * M_PI,   5 * M_PI), 5 * M_PI);
		requireEqual(dr::angleFrom(3.5 * M_PI, 5 * M_PI), 5.5 * M_PI);

		// negative from angle
		requireEqual(dr::angleFrom(-3 * M_PI,   -5 * M_PI), -5 * M_PI);
		requireEqual(dr::angleFrom(-3.5 * M_PI, -5 * M_PI), -3.5 * M_PI);

	}

	SECTION("testSquare") {
		requireEqual(dr::square(2), 4);
		requireEqual(dr::square(-2), 4);
		requireNear(dr::square(M_PI), 9.86960440108935861883, 0.000001);
		requireNear(dr::square(-M_PI), 9.86960440108935861883, 0.000001);
	}

	SECTION("testSquareSum") {
		requireEqual(dr::square_sum(2.0, 2.0), 8.0);
		requireEqual(dr::square_sum(1.0, 2.0, 3.0, 4.0, 5.0), 55.0);
		requireEqual(dr::square_sum(-1.0, -2.0, -3.0, -4.0, -5.0), 55.0);
	}

	SECTION("testLength") {
		requireEqual(dr::length(1.0, 0.0, 0.0), 1.0);
		requireNear(dr::length(10.0, 10.0, 0.0), 14.1421356237309504880, 0.0000001); // sqrt(10*10 + 10*10)
		requireEqual(dr::length(0.0, 0.0, 0.0), 0.0);
	}

	SECTION("testAngle") {
		requireEqual(dr::angle(std::sqrt(2), 1.0, 1.0), M_PI_2);
	}
}


/*
TEST_CASE("GeometryTest -- testPi", "testPi") {
	// test equality with C defined pi
	requireEqual(dr::pi(), M_PI);
}

TEST_CASE("GeometryTest -- testDegrees", "testDegrees") {
	// test normal use case
	requireEqual(dr::degrees(0),   0);
	requireEqual(dr::degrees(180), M_PI);
	requireEqual(dr::degrees(360), 2 * M_PI);
	requireNear(dr::degrees(37), 0.645771823237901, 0.0000001); // 37 / 180 * pi

	// test negativity
	requireEqual(dr::degrees(-180), -M_PI);
	requireEqual(dr::degrees(-360), -2 * M_PI);
}

TEST_CASE("GeometryTest -- testToDegrees", "testToDegrees") {
	// test normal use case
	requireEqual(dr::to_degrees(0), 0);
	requireEqual(dr::to_degrees(M_PI), 180);
	requireEqual(dr::to_degrees(2 * M_PI), 360);
	requireNear(dr::to_degrees(0.645771823237901), 37, 0.0000001); // 37 / 180 * pi

	// test negativity
	requireEqual(dr::to_degrees(-M_PI), -180);
	requireEqual(dr::to_degrees(-2 * M_PI), -360);
}

TEST_CASE("GeometryTest -- testSign", "testSign") {
	// normal use cases
	REQUIRE(dr::sign(-1) == -1);
	REQUIRE(dr::sign(1)  ==  1);
	REQUIRE(dr::sign(0)  ==  0);

	// double use cases
	REQUIRE(dr::sign(M_PI)  == 1);
	REQUIRE(dr::sign(-M_PI) == -1);
	REQUIRE(dr::sign(std::numeric_limits<double>::quiet_NaN()) == 0);
}

TEST_CASE("GeometryTest -- testNormalizeAngle", "testNormalizeAngle") {
	// normal use
	requireEqual(dr::normalizeAngle(3 * M_PI), M_PI);
	requireEqual(dr::normalizeAngle(3.5 * M_PI), 1.5 * M_PI);

	// negativity
	requireEqual(dr::normalizeAngle(-3 * M_PI), M_PI);
	requireEqual(dr::normalizeAngle(-3.5 * M_PI), 0.5 * M_PI);
}

TEST_CASE("GeometryTest -- testAngleFrom", "testAngleFrom") {
	// same as normalizeAngle

	// normal use
	requireEqual(dr::angleFrom(3 * M_PI,   0), M_PI);
	requireEqual(dr::angleFrom(3.5 * M_PI, 0), 1.5 * M_PI);

	// negative angle
	requireEqual(dr::angleFrom(-3 * M_PI,   0), M_PI);
	requireEqual(dr::angleFrom(-3.5 * M_PI, 0), 0.5 * M_PI);

	// set different angle

	// normal use
	requireEqual(dr::angleFrom(3 * M_PI,   5 * M_PI), 5 * M_PI);
	requireEqual(dr::angleFrom(3.5 * M_PI, 5 * M_PI), 5.5 * M_PI);

	// negative from angle
	requireEqual(dr::angleFrom(-3 * M_PI,   -5 * M_PI), -5 * M_PI);
	requireEqual(dr::angleFrom(-3.5 * M_PI, -5 * M_PI), -3.5 * M_PI);

}

TEST_CASE("GeometryTest -- testSquare", "testSquare") {
	requireEqual(dr::square(2), 4);
	requireEqual(dr::square(-2), 4);
	requireNear(dr::square(M_PI), 9.86960440108935861883, 0.000001);
	requireNear(dr::square(-M_PI), 9.86960440108935861883, 0.000001);
}

TEST_CASE("GeometryTest -- testSquareSum", "testSquareSum") {
	requireEqual(dr::square_sum(2.0, 2.0), 8.0);
	requireEqual(dr::square_sum(1.0, 2.0, 3.0, 4.0, 5.0), 55.0);
	requireEqual(dr::square_sum(-1.0, -2.0, -3.0, -4.0, -5.0), 55.0);
}

TEST_CASE("GeometryTest -- testLength", "testLength") {
	requireEqual(dr::length(1.0, 0.0, 0.0), 1.0);
	requireNear(dr::length(10.0, 10.0, 0.0), 14.1421356237309504880, 0.0000001); // sqrt(10*10 + 10*10)
	requireEqual(dr::length(0.0, 0.0, 0.0), 0.0);
}

TEST_CASE("GeometryTest --testAngle", "testAngle") {
	requireEqual(dr::angle(std::sqrt(2), 1.0, 1.0), M_PI_2);
}

*/
