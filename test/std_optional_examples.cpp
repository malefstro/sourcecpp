#include <iostream>
#include "catch.hpp"
#include <var_utils_01.hpp>
#include <common/Person.hpp>

using namespace std;

TEST_CASE("simple assertions for optional", "[std_optional]")
{
    optional<int> o;
    REQUIRE(!o.has_value());
    o = 20;
    REQUIRE(o.has_value());
}

TEST_CASE("safe parse to int", "[std_optional]")
{
    auto maybe_uint64_t1 = varu::safe_parse_str_to_uint64_t("77272");
    REQUIRE(maybe_uint64_t1.has_value());
    REQUIRE(maybe_uint64_t1.value() == 77272);

    auto maybe_uint64_t2 = varu::safe_parse_str_to_uint64_t("test");
    REQUIRE(!maybe_uint64_t2.has_value());

    auto maybe_uint64_t3 = varu::safe_parse_str_to_uint64_t("-2");
    REQUIRE(!maybe_uint64_t3.has_value());

    auto maybe_uint64_t4 = varu::safe_parse_str_to_uint64_t("21321377272");
    REQUIRE(maybe_uint64_t4.has_value());
    REQUIRE(maybe_uint64_t4.value() == 21321377272);

}

TEST_CASE("create a Person with optional", "[std_optional]")
{
    varu::Person p {"name1 surname2", 10, "693833333", nullopt};

    cout << p;

    REQUIRE(p.getCellNumber().has_value());
    REQUIRE(!p.getHomeNumber().has_value());

}