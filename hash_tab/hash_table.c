#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

static ht_item *ht_new_item(const char *k, const char *v)
{
	ht_item *i = malloc(sizeof(ht_item));
	if (ht_item == NULL) {
		fprintf(stderr, "ht_new_item: could not allocate memory\n");
		exit(EXIT_FAILURE);
	}

	i->key = strdup(k);
	i->value = strdup(v);
	return i;
}

int main()
{
	return 0;
}
