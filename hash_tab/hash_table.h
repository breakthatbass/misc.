#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

typedef struct {
	char *key;
	char *value;
} ht_item;

typedef struct {
	int size;
	int count;
	ht_item **items;
} ht_hash_table;

#endif
