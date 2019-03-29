#include "catch.hpp"
#include "exceptions.h"
#include "StringDLinkedList.h"
#include <sstream>
#include <iostream>
using std::cout;
using std::ostringstream;

TEST_CASE("Testing StringDLinkedList class") {
	
	SECTION("Testing push_front function and front functions.") {
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

	SECTION("Testing push_back and back functions.") {
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

	SECTION("Testing pop_front") {
		StringDLinkedList test;
		test.push_back("Hello");
		test.push_back("There");
		test.push_back("How");
		test.push_back("Are");
		test.push_back("You?");

		test.pop_front();
		REQUIRE(test.front() == "There");

		test.pop_front();
		REQUIRE(test.front() == "How");

		test.pop_front();
		REQUIRE(test.front() == "Are");

		test.pop_front();
		REQUIRE(test.front() == "You?");

		test.pop_front();
		REQUIRE_THROWS_AS(test.front(), EmptyList);

		REQUIRE_THROWS_AS(test.pop_front(), EmptyList);
	}

	SECTION("Testing pop_back") {
		StringDLinkedList test;
		test.push_back("Hello");
		test.push_back("There");
		test.push_back("How");
		test.push_back("Are");
		test.push_back("You?");

		test.pop_back();
		REQUIRE(test.back() == "Are");

		test.pop_back();
		REQUIRE(test.back() == "How");

		test.pop_back();
		REQUIRE(test.back() == "There");

		test.pop_back();
		REQUIRE(test.back() == "Hello");

		test.pop_back();
		//Ask how to test this particular case.

		REQUIRE_THROWS_AS(test.pop_back(), EmptyList);
	}

	SECTION("Testing remove_inst") {
		//Still pending.
	}

	SECTION("Testing front_print") {
		ostringstream out;
		StringDLinkedList test;
		test.push_back("Hello");
		test.push_back("There");
		test.push_back("How");
		test.push_back("Are");
		test.push_back("You?");

		test.front_print(out);
		REQUIRE(out.str() == " --- ");
	}

	SECTION("Testing back_print") {
		ostringstream out;
		StringDLinkedList test;
		test.push_back("Hello");
		test.push_back("There");
		test.push_back("How");
		test.push_back("Are");
		test.push_back("You?");

		test.back_print(out);

		REQUIRE(" " == " ");
	}
}