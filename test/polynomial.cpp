// C++
#include <cmath>

// Catch2
#include <catch2/catch.hpp>

// This repository
#include "polynomial.hpp"

namespace {
	void requireEqual(float const & a, float const & b)
	{
		REQUIRE_THAT(a, Catch::WithinULP(b, 0));
	}
}

TEST_CASE("PolynomialTest -- emptyPolynomial", "emptyPolynomial") {
	dr::Polynomial p;
	requireEqual(0, p.y(0.0));
	requireEqual(0, p.y(0.5));
	requireEqual(0, p.y(1.0));
	requireEqual(0, p.y(-0.5));
	requireEqual(0, p.y(-1.0));
}

TEST_CASE("PolynomialTest -- constantPolynomial", "constantPolynomial") {
	dr::Polynomial p;
	p.terms.emplace_back(3.25, 0);

	requireEqual(3.25, p.y( 0.0));
	requireEqual(3.25, p.y( 0.5));
	requireEqual(3.25, p.y( 1.0));
	requireEqual(3.25, p.y(-0.5));
	requireEqual(3.25, p.y(-1.0));
}

TEST_CASE("PolynomialTest -- squareRoot", "squareRoot") {
	dr::Polynomial p;
	p.terms.emplace_back(1, 0.5);

	requireEqual( 0.000, p.y(0.0));
	requireEqual( 1.000, p.y(1.0));
	requireEqual( 2.000, p.y(4.0));

	REQUIRE(std::isnan(p.y(-1.0)) == true);
	REQUIRE(std::isnan(p.y(-4.0)) == true);
}

TEST_CASE("PolynomialTest -- firstOrder", "firstOrder") {
	dr::Polynomial p;
	p.terms.emplace_back(2, 1);

	requireEqual( 0, p.y(0.0));
	requireEqual( 1, p.y(0.5));
	requireEqual( 2, p.y(1.0));
	requireEqual(-1, p.y(-0.5));
	requireEqual(-2, p.y(-1.0));
}

TEST_CASE("PolynomialTest -- thirdOrder", "thirdOrder") {
	dr::Polynomial p;
	p.terms.emplace_back(2,   1);
	p.terms.emplace_back(1.5, 3);

	requireEqual( 0.0000, p.y(0.0));
	requireEqual( 1.1875, p.y(0.5));
	requireEqual( 3.5000, p.y(1.0));
	requireEqual(-1.1875, p.y(-0.5));
	requireEqual(-3.5000, p.y(-1.0));
}

TEST_CASE("PolynomialTest -- fourthOrder", "fourthOrder") {
	dr::Polynomial p;
	p.terms.emplace_back(1, 2);
	p.terms.emplace_back(2, 4);

	requireEqual( 0.000, p.y(0.0));
	requireEqual( 0.375, p.y(0.5));
	requireEqual( 3.000, p.y(1.0));
	requireEqual(36.000, p.y(2.0));
	requireEqual( 0.375, p.y(-0.5));
	requireEqual( 3.000, p.y(-1.0));
	requireEqual(36.000, p.y(-2.0));
}
