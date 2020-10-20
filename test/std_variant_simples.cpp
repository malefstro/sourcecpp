#include "catch.hpp"
#include <variant>
#include <iostream>

using namespace std;

TEST_CASE("simple variants", "[std_optional]")
{
    variant<int, bool, string> v0 {42};
    REQUIRE(holds_alternative<int>(v0));
    REQUIRE(!holds_alternative<string>(v0));

    auto* s = get_if<string>(&v0);
    REQUIRE(!s);
    auto* i = get_if<int>(&v0);
    REQUIRE(*i == 42);
}

TEST_CASE("simple variants example 2", "[std_optional]")
{

    struct admin {
        void admin_permissions() {
            cout << "I am an admin now" << endl;
            is_admin_ = true;
        }

        bool is_admin_ {false};

    };

    struct normal {
        void normal_permissions() {
            cout << "I am a normal user" << endl;
            is_admin_ = false;
        }

        bool is_admin_ {false};
    };

    variant<normal, admin> user;

    admin ad1;
    user = ad1;

    if (auto* u = get_if<admin>(&user)) {
        u->admin_permissions();
    } else if (auto* l = get_if<normal>(&user)) {
        l->normal_permissions();
    }

}

TEST_CASE("simple variants, visit", "[std_optional]")
{
    struct printer {
        void operator()(int x) { cout << x << "i" << endl;}
        void operator()(float x) { cout << x << "f" << endl;}
        void operator()(double x) { cout << x << "d" << endl;}
    };

    using my_variant = variant<int, float, double>;
    my_variant v1 {12.3f};
    visit(printer{}, v1);
}