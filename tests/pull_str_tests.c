#include "minunit/minunit.h"
#include "../strlib.h"

#include <stdlib.h>

static char *a = "<p>hello this is a string</p>";
static char *b = "<div class='foo'>this is another string</div>";
static char *c = "this string is meant to fail";
static char *a_parsed;
static char *b_parsed;
static char *c_parsed;

void test_setup(void)
{
    a_parsed = between_two_ferns(a, "<p>", "</p>");
    b_parsed = between_two_ferns(b, "foo'>", "</div>");
    c_parsed = between_two_ferns(c, "foo", "bar");
}

void test_teardown(void)
{ 
    free(a_parsed);
    free(b_parsed);
}

MU_TEST(test_check)
{
    mu_check(c_parsed == NULL);
}

MU_TEST(test_string_eq)
{
    mu_assert_string_eq(a_parsed, "hello this is a string");
    mu_assert_string_eq(b_parsed, "this is another string");
}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_string_eq);
    MU_RUN_TEST(test_check);
}


int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
