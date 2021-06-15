#include "minunit/minunit.h"
#include "../strlib.h"

#include <assert.h>
#include <stdlib.h>

#define BUF 50

static char *hello;
static char *cat;
static char *move_ptr;

static char *new_hello;
static char *new_cat;
static char *new_move_ptr;

static char *fern1 = "<p>hello how are you</p>";
static char *fern2 = "<html><body>this is the body of the page</body></html>";
static char *fern3 = NULL;
static char *fern4 = "foo bar baz";

static char *new_fern1;
static char *new_fern2;
static char *new_fern3;
static char *new_fern4;

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
*
* between_two_ferns(char *start, char *end);
*   -> searches for start and end and returns the substring
*      that is between the two substrings.
* */

void test_setup(void)
{
    hello = malloc(BUF);
    new_hello = malloc(BUF);
    cat = malloc(BUF);
    new_cat = malloc(BUF);
    move_ptr = malloc(BUF);

    strcpy(hello, "hello, how are you");
    strcpy(cat, "the cat went to town");
    strcpy(move_ptr, "the needle in the haystack");
}

void test_teardown(void)
{
    free(hello);
    free(cat);
    free(new_hello);
    free(new_cat);
    free(move_ptr);
}

MU_TEST(test_check)
{
    // force some null returns
    char *empty1 = NULL;
    char *empty2 = NULL;
    mu_check(cpy_until(empty1, empty2, 'x') == NULL);
    mu_check(strafter(empty1, empty2) == NULL);
}

MU_TEST(test_string_eq)
{
    cpy_until(new_hello, hello, 'a');
    mu_assert_string_eq(new_hello, "hello, how ");

    replace(cat, 'z', 'x', FIRST);
    mu_assert_string_eq(cat, "the cat went to town");
    replace(cat, 't', 'z', ALL);
    mu_assert_string_eq(cat, "zhe caz wenz zo zown");

    new_move_ptr = strafter(move_ptr, "needle ");
    mu_assert_string_eq(new_move_ptr, "in the haystack");

    new_fern1 = between_two_ferns(fern1, "<p>", "</p>");
    mu_assert_string_eq(new_fern1, "hello how are you");

    new_fern2 = between_two_ferns(fern2, "<body>", "</p>");
    mu_assert_string_eq(new_fern2, NULL);

    new_fern3 = between_two_ferns(fern3, "<body>", "</p>");
    mu_assert_string_eq(new_fern3, NULL);
    
    new_fern4 = between_two_ferns(fern4, NULL, NULL);
    mu_assert_string_eq(new_fern4, "foo bar baz");
}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_check);
    MU_RUN_TEST(test_string_eq);
}


int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
