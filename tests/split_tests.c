#include "minunit/minunit.h"
#include "../src/split.h"
#include <stdlib.h>

static char teststr1[] = "hello how are you";
static char teststr2[] = "hjksdfh";
static char teststr3[] = "";
static char teststr4[] = "this | string\nhas w many, delimiters";
static char teststr5[] = "one, two, three, four, five";
static char **hello;
static char **junk;
static char **empty;
static char **many_delims;
static char **num_str;

void test_setup(void)
{
    hello = split(teststr1, " ");
    junk = split(teststr2, " ");
    empty = split(teststr3, " ");
    many_delims = split(teststr4, " |\nw,");
    num_str = split(teststr5, ",");
}

void test_teardown(void)
{
    free(hello);
    free(junk);
    free(empty);
    free(many_delims);
    free(num_str);
}

MU_TEST(test_string_eq)
{
    mu_assert_string_eq(hello[0], "hello");
    mu_assert_string_eq(hello[1], "how");
    mu_assert_string_eq(hello[2], "are");
    mu_assert_string_eq(hello[3], "you");

    mu_assert_string_eq(many_delims[0], "this");
    mu_assert_string_eq(many_delims[1], "string");
    mu_assert_string_eq(many_delims[2], "has");
    mu_assert_string_eq(many_delims[3], "many");
    mu_assert_string_eq(many_delims[4], "delimiters");

    mu_assert_string_eq(num_str[0], "one");
    mu_assert_string_eq(num_str[1], "two");
    mu_assert_string_eq(num_str[2], "three");
    mu_assert_string_eq(num_str[3], "four");
    mu_assert_string_eq(num_str[4], "five");
}

MU_TEST(test_check) {
	mu_check(empty == NULL);
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
