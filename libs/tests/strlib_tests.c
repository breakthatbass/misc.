#include "minunit/minunit.h"
#include "../strlib.h"

static char *hello = "hello, how are you";
static char *cat = "the cat went to town";
static char *move_ptr = "After the test, this will be the new string";

/* *
* functions to test:
*
* cpy_until(str dst, str s, char t)
*   -> cpy str s into str dst char by char until t is encountered
*
* replace(str s, char orig, char repl, config)
*   -> replace char orig with char repl in str s.
*   -> config:
*       FIRST: replaces first instances of char orig
*       ALL:   replaces all instances of char orig
*
* strafter(haystack, needle);
*   -> searches for substring needle in string haystack
*      if found, returns pointer to position after haystack
* */

void test_setup(void)
{

}

void test_teardown(void)
{

}

MU_TEST(...)
{

}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_check);
}


int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
