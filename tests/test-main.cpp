#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <_sample/_sample.h>

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("foo test") {
    foo f(5);
    CHECK(f.bar == 5);
    f.add(3);
    CHECK(f.bar == 8);
}
