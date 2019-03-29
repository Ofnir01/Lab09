#include "catch.hpp"
#include "StringDLinkedList.h"

TEST_CASE("Testing StringDLinkedList class") {
	
	SECTION("Testing push_front function") {
		StringDLinkedList test;
		test.push_front("You?");
		REQUIRE(test.front() == "You?");

		test.push_front("Are");
		REQUIRE(test.front() == "Are");

		test.push_front("How");
		REQUIRE(test.front() == "How");

		test.push_front("There");
		REQUIRE(test.front() == "There");

		test.push_front("Hello");
		REQUIRE(test.front() == "Hello");
		REQUIRE(test.back() == "You?");
	}

	SECTION("Testing push_back function") {
		StringDLinkedList test;
		
		test.push_back("Hello");
		REQUIRE(test.back() == "Hello");

		test.push_back("There");
		REQUIRE(test.back() == "There");

		test.push_back("How");
		REQUIRE(test.back() == "How");

		test.push_back("Are");
		REQUIRE(test.back() == "Are");

		test.push_back("You?");
		REQUIRE(test.back() == "You?");
		REQUIRE(test.front() == "Hello");
	}
}