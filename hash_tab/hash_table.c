#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"

static ht_item *ht_new_item(const char *k, const char *v)
{
	ht_item *i = malloc(sizeof(ht_item));
	if (i == NULL) {
		fprintf(stderr, "ht_new_item: could not allocate memory\n");
		exit(EXIT_FAILURE);
	}

	i->key = strdup(k);
	i->value = strdup(v);
	return i;
}


ht_hash_table *ht_new()
{
	ht_hash_table *ht = malloc(sizeof(ht_hash_table));
	if (ht == NULL) {
		fprintf(stderr, "ht_new: could not allocate memory\n");
		exit(EXIT_FAILURE);
	}

	ht->size = 53;
	ht->count = 0;
	ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
	return ht;
}

static void ht_del_item(ht_item *i)
{
	free(i->key);
	free(i->value);
	free(i);
}

void ht_del_hash_table(ht_hash_table *ht)
{
	for (int i = 0; i < ht->size; i++) {
		ht_item *item = ht->items[i];
		if (item != NULL) {
			ht_del_item(item);
		}
	}
	free(ht->items);
	free(ht);
}

static int ht_hash(const char *s, const int a, const int m)
{
	long hash = 0;
	const int len_s = strlen(s);
	for (int i = 0; i < len_s; i++) {
		hash += (long)pow(a, len_s - (i+1)) * s[i];
		hash = hash % m;
	}
	return (int) hash;
}


// ht_get_hash: a second hashing function to reduce collision occurances
static int ht_get_hash (const char *s, const int num_buckets, const int attempt)
{
	const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

int main()
{
	ht_hash_table *ht = ht_new();
	ht_del_hash_table(ht);

	int h = ht_hash("cat", 163, 53);
	printf("%d\n", h);
	
	return 0;
}
