#include "doctest.h"
#include "../test.h"
#include "value.h"
#include "utils.h"

TEST_CASE( "values can be converted to strings" )
{
    SUBCASE( "converting a boolean to a string" ) {
        bool value = true;
        std::string str = Gpds::valueToString(value);
        REQUIRE(str == "true");
    }

    SUBCASE( "converting an integer to a string" ) {
        int value = 10;
        std::string str = Gpds::valueToString(value);
        REQUIRE(str == "10");
    }

    SUBCASE( "converting a double to a string" ) {
        double value = 1.25;
        std::string str = Gpds::valueToString(value);
        REQUIRE(str == "1.25");
    }

    SUBCASE( "converting a string to a string" ) {
        std::string value = "F82GA3B";
        std::string str = Gpds::valueToString(value);
        REQUIRE(str == "F82GA3B");
    }

    SUBCASE( "converting a c-string to a string" ) {
        const char* value = "E2FEB55";
        std::string str = Gpds::valueToString(value);
        REQUIRE(str == "E2FEB55");
    }

    SUBCASE( "converting an invalid type to a string" ) {
        std::vector<std::string> vec;
        std::string str = Gpds::valueToString(vec);
        REQUIRE(str.empty());
    }
}

TEST_CASE( "strings can be converted back into values" )
{
    SUBCASE( "converting a string to a boolean" ) {
        std::string str = "false";
        auto value = Gpds::stringToValue<bool>(str);
        REQUIRE(value.has_value());
        REQUIRE(value.value() == false);
    }

    SUBCASE( "converting a string to a integer" ) {
        std::string str = "12345";
        auto value = Gpds::stringToValue<int>(str);
        REQUIRE(value.has_value());
        REQUIRE(value.value() == 12345);
    }

    SUBCASE( "converting a string containing a negative number to an integer" ) {
        std::string str = "-1234";
        auto value = Gpds::stringToValue<int>(str);
        REQUIRE(value.has_value());
        REQUIRE(value.value() == -1234);
    }

    SUBCASE( "converting a string to a double" ) {
        std::string str = "1.33333333";
        auto value = Gpds::stringToValue<double>(str);
        REQUIRE(value.has_value());
        REQUIRE(value.value() == doctest::Approx(1.33333333));
    }

    SUBCASE( "converting a string containing a negative decimal to a double" ) {
        std::string str = "-1.33333333";
        auto value = Gpds::stringToValue<double>(str);
        REQUIRE(value.has_value());
        REQUIRE(value.value() == doctest::Approx(-1.33333333));
    }

    SUBCASE( "converting a string to a string" ) {
        std::string str = "R8BB45C";
        auto value = Gpds::stringToValue<std::string>(str);
        REQUIRE(value.has_value());
        REQUIRE(value.value() == str);
    }
}
