 //AUTHORS: <Ariel saadon>

#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <algorithm>

using namespace ariel;
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Hat change code") {
	//Straw Hat
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	//Mexican Hat
    CHECK(nospaces(snowman(21111111)) == nospaces("___\n.....\n(.,.)\n<( : )>\n( : )"));
	//Fez
    CHECK(nospaces(snowman(31111111)) == nospaces("_\n/_\\\n(.,.)\n<( : )>\n( : )"));
	//Russian Hat
    CHECK(nospaces(snowman(41111111)) == nospaces("___\n(_*_)\n(.,.)\n<( : )>\n( : )"));
}

TEST_CASE("Nose/Mouth change code") {
	//Normal
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	//Dot
    CHECK(nospaces(snowman(12111111)) == nospaces("_===_\n(...)\n<( : )>\n( : )"));
	//Line
    CHECK(nospaces(snowman(13111111)) == nospaces("_===_\n(._.)\n<( : )>\n( : )"));
	//None
    CHECK(nospaces(snowman(14111111)) == nospaces("_===_\n(. .)\n<( : )>\n( : )"));
}

TEST_CASE("Left Eye change code") {
	//Dot
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	//Bigger Dot
    CHECK(nospaces(snowman(11211111)) == nospaces("_===_\n(o,.)\n<( : )>\n( : )"));
	//Biggest Dot 
    CHECK(nospaces(snowman(11311111)) == nospaces("_===_\n(O,.)\n<( : )>\n( : )"));
	//Closed
    CHECK(nospaces(snowman(11411111)) == nospaces("_===_\n(-,.)\n<( : )>\n( : )"));
}

TEST_CASE("Right Eye change code") {
	//Dot
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	//Bigger Dot
    CHECK(nospaces(snowman(11121111)) == nospaces("_===_\n(.,o)\n<( : )>\n( : )"));
	//Biggest Dot 
    CHECK(nospaces(snowman(11131111)) == nospaces("_===_\n(.,O)\n<( : )>\n( : )"));
	//Closed
    CHECK(nospaces(snowman(11141111)) == nospaces("_===_\n(.,-)\n<( : )>\n( : )"));
}

TEST_CASE("Left Arm change code") {
	//Normal Arm
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	//Upwards Arm
    CHECK(nospaces(snowman(11112111)) == nospaces("_===_\n\\(.,.)\n( : )>\n( : )"));
	//Downwards Arm
    CHECK(nospaces(snowman(11113111)) == nospaces("_===_\n(.,.)\n/( : )>\n( : )"));
	//None
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
}

TEST_CASE("Right Arm change code") {
	//Normal Arm
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	//Upwards Arm
    CHECK(nospaces(snowman(11111211)) == nospaces("_===_\n(.,.)/\n<( : )\n( : )"));
	//Downwards Arm
    CHECK(nospaces(snowman(11111311)) == nospaces("_===_\n(.,.)\n<( : )\\\n( : )"));
	//None
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
}

TEST_CASE("Torso change code") {
	//Buttons
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	//Vest
    CHECK(nospaces(snowman(11111121)) == nospaces("_===_\n(.,.)\n<(] [)>\n( : )"));
	//Inward Arms
    CHECK(nospaces(snowman(11111131)) == nospaces("_===_\n(.,.)\n<(> <)>\n( : )"));
	//None
    CHECK(nospaces(snowman(11111141)) == nospaces("_===_\n(.,.)\n<(   )>\n( : )"));
}

TEST_CASE("Base change code") {
	//Buttons
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	//Feet
    CHECK(nospaces(snowman(11111112)) == nospaces("_===_\n(.,.)\n<( : )>\n(\" \")"));
	//Flat
    CHECK(nospaces(snowman(11111113)) == nospaces("_===_\n(.,.)\n<( : )>\n(___)"));
	//None
    CHECK(nospaces(snowman(11111114)) == nospaces("_===_\n(.,.)\n<( : )>\n(   )"));
}

//Bad snowman code Tests
TEST_CASE("Short input") {
    CHECK_THROWS(snowman(1));
	CHECK_THROWS(snowman(22));
	CHECK_THROWS(snowman(333));
	CHECK_THROWS(snowman(4444));
	CHECK_THROWS(snowman(55555));
	CHECK_THROWS(snowman(666666));
	CHECK_THROWS(snowman(7777777));
}

TEST_CASE("Long input") {
	CHECK_THROWS(snowman(111111111));
	CHECK_THROWS(snowman(1212121212));
	CHECK_THROWS(snowman(1234123412));
	CHECK_THROWS(snowman(515255467));
	CHECK_THROWS(snowman(454545445));
	CHECK_THROWS(snowman(888888888));
}

TEST_CASE("Negative numbers") {
	CHECK_THROWS(snowman(-1));
	CHECK_THROWS(snowman(-12));
	CHECK_THROWS(snowman(-123));
	CHECK_THROWS(snowman(-1234));
	CHECK_THROWS(snowman(-12341));
	CHECK_THROWS(snowman(-123412));
	CHECK_THROWS(snowman(-1234123));

	CHECK_THROWS(snowman(-11234123));
	CHECK_THROWS(snowman(1-1234123));
	CHECK_THROWS(snowman(11-234123));
	CHECK_THROWS(snowman(112-34123));
	CHECK_THROWS(snowman(1123-4123));
	CHECK_THROWS(snowman(11234-123));
	CHECK_THROWS(snowman(112341-23));
	CHECK_THROWS(snowman(1123412-3));

	CHECK_THROWS(snowman(-1-1-1-1-1-1-1-1));
	CHECK_THROWS(snowman(-1-2-3-4-1-2-3-4));
	CHECK_THROWS(snowman(-1-2-3-4-5-6-7-8));
	CHECK_THROWS(snowman(-5-5-5-5-5-5-5-5));
}

TEST_CASE("One invalid letter") {
	CHECK_THROWS(snowman(91111111));
	CHECK_THROWS(snowman(19111111));
	CHECK_THROWS(snowman(22922222));
	CHECK_THROWS(snowman(22292222));
	CHECK_THROWS(snowman(33339333));
	CHECK_THROWS(snowman(33333933));
	CHECK_THROWS(snowman(44444494));
	CHECK_THROWS(snowman(44444449));
}

