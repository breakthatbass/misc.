#include "minunit/minunit.h"
#include "../llist.h"

#define MAX_ELE 20

static list_t *l;

void push_to_list(list_t *l, int max)
{
    for(int i = 0; i < max; i++)
        push(l, i);
}

void test_setup(void)
{
    l = list_init();
    push_to_list(l, MAX_ELE);

}

void test_teardown(void)
{

}

MU_TEST()
{

}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_string_eq);
}


int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}