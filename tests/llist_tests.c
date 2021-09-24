#include "minunit/minunit.h"
#include "../src/llist.h"

#define MAX_ELE 10

/* functions to test:
 *
 * shift(list) -> remove last node
 * pop(list) -> remove first node
 *
 * get_size(list) -> get the number of nodes in the list
 *
 * push(list, value) -> add node to beginning of list
 * append(list, value) -> add node to end of list
 *
 * remove_node(list, value) -> remove requested node
 *
 * search(list, value) -> search list for a value
 *
 * */

static list_t *list_of_10_ele;
static list_t *list_of_1_ele;
static list_t *sort_test_list;

// variables for testing pop and shift
static int pop_val_10;
static int shift_val_10;
static int pop_val_1;
static int shift_val_1;

static void push_to_list(list_t *l, int max)
{
    for(int i = 0; i < max; i++)
        push(l, i);
}

void test_setup(void)
{
    list_of_10_ele = list_init();
    list_of_1_ele = list_init();
	sort_test_list = list_init();

    // load up 20 element list
    push_to_list(list_of_10_ele, MAX_ELE);
    // load up 1 list
    push(list_of_1_ele, 15);
}

void test_teardown(void)
{
    destroy_list(list_of_10_ele);
    destroy_list(list_of_1_ele);
	destroy_list(sort_test_list);
}

MU_TEST(test_check)
{
	/**********************************
	 * GET_SIZE TESTS 
	 **********************************/
	size_t small_list, large_list;
    small_list = get_size(list_of_1_ele);
	large_list = get_size(list_of_10_ele);

	mu_check(small_list == 1);
	mu_check(large_list == 10);

	/**********************************
	 * POP TESTS
	 **********************************/
	pop_val_1 = shift(list_of_1_ele);
	pop_val_10 = shift(list_of_10_ele);

	mu_check(pop_val_1 == 15);
	mu_check(pop_val_10 == 0);

	/**********************************
	 * SHIFT TESTS
	 **********************************/
	// refill list of one element
	push(list_of_1_ele, 15);

	shift_val_1 = pop(list_of_1_ele);
	shift_val_10 = pop(list_of_10_ele);

	mu_check(shift_val_1 == 15);
	mu_check(shift_val_10 == 9);

	/**********************************
	 * REMOVE NODE TESTS
	 **********************************/
	push(list_of_1_ele, 15);
	int rem_node = remove_node(list_of_1_ele, 15);
	mu_check(rem_node == 1);

	rem_node = remove_node(list_of_10_ele, 123);
	mu_check(rem_node == -1);

	/**********************************
	 * SEARCH TESTS
	 **********************************/
	 push(list_of_1_ele, 15);
	 mu_check(search(list_of_1_ele, 15) == 15);
	 mu_check(search(list_of_1_ele, 5) == -1);

	 mu_check(search(list_of_10_ele, 2) == 2);
	 mu_check(search(list_of_10_ele, 123) == -1);

	 /**********************************
	 * PUSH/APPEND TESTS
	 **********************************/
	 push(list_of_1_ele, 1);
	 push(list_of_10_ele, 50);
	 mu_check(get_size(list_of_1_ele) == 2);
	 mu_check(get_size(list_of_10_ele) == 9);

	 append(list_of_1_ele, 1);
	 append(list_of_10_ele, 50);
	 mu_check(get_size(list_of_1_ele) == 3);
	 mu_check(get_size(list_of_10_ele) == 10);

	 // then we make sure append was added to the end
	 mu_check(pop(list_of_1_ele) == 1);
	 mu_check(pop(list_of_10_ele) == 50);

	 // then shift, same numbers in front
	 mu_check(shift(list_of_1_ele) == 1);
	 mu_check(shift(list_of_10_ele) == 50);

	 /**********************************
	 * SORT TESTS
	 **********************************/
	push(sort_test_list, 5);
	push(sort_test_list, 7);
	push(sort_test_list, 3);

	// list is [5, 7, 3]
	sort_list(sort_test_list);
	// should now be [3, 5, 7]
	mu_check(pop(sort_test_list) == 3);
	mu_check(pop(sort_test_list) == 5);
	mu_check(pop(sort_test_list) == 7);

	// test on an empty list
	sort_list(sort_test_list);
	mu_check(sort_test_list->nodes == 0);


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
