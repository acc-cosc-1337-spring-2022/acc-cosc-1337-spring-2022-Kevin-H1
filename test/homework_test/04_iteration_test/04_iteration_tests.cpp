#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test factorial funciton")
{
	REQUIRE(6 == factorial(3));
	REQUIRE(120 == factorial(5));
	REQUIRE(720 == factorial(6));
}

TEST_CASE("Test GCD function")
{
	REQUIRE(5 == gcd(5, 15));
	REQUIRE(7 == gcd(21, 28));
	REQUIRE(25 == gcd(25, 100));
}