#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "../src/word_iterator.hpp"

TEST_CASE("Bidirectional iterator"){
    const std::string x{ "this is a test" };
    word_iterator i{ x };
    REQUIRE( *i == "this" );
    REQUIRE( *(++i) == "is" );
    REQUIRE( *(i++) == "is" );
    REQUIRE( *i == "a" );
    REQUIRE( *(--i) == "is" );
    REQUIRE( *(i--) == "is" );
    REQUIRE( *i == "this" );
    word_iterator j{ x };
    REQUIRE( i == j );
    REQUIRE( *i == *j);
    REQUIRE( ++i != j);
    const std::string y{ "this is a test" };
    j = { y };
    REQUIRE(i != ++j);
    REQUIRE(*i == *j);
};

