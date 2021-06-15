#include <stdio.h>
#include <stdlib.h>

#include "llist.h"
#include <assert.h>

int main()
{
    list_t *l = NULL;
    l = list_init();

    append(l, 23);
    push(l, 12);
    push(l, 538);
    append(l, 42);

    // 538 --> 12 --> 23 --> 42
    
    //print_list(l);
    assert(shift(l) == 538);
    assert(shift(l) == 12);

    destroy_list(l);

    return 0;
}
