#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// basic node structure
typedef struct __node_t {
	int key;
	struct __node_t *next;
} node_t;

// basic list structure (one used per list)
typedef struct __list_t {
	node_t *head;
} list_t;


// initiate a list and lock
void list_init(list_t *ll)
{
	ll->head = NULL;
}


void list_insert(list_t *ll, int key)
{
	//pthread_mutex_lock(&ll->lock);
	node_t *new = malloc(sizeof(node_t));
	if (new == NULL) {
		perror("malloc");
		//pthread_mutex_unlock(&ll->lock);
		return;
	}
	new->key = key;
	new->next = ll->head;
	ll->head = new;
}


int list_lookup(list_t *ll, int key)
{
	int rv = -1;
	node_t *cur = ll->head;
	while(cur) {
		if (cur->key == key) {
			// pthread_mutex_unlock(&ll->lock);
			rv = 0;
			break;
		}
		cur = cur->next;
	}
	return rv;	// not found
}


// get_num: get random num and add it to list
void get_num(list_t *ll)
{
	int ceil = 999;

	srand(time(0));
	for (int i = 0; i < 90000000; i++) {
		int n = (rand() % (ceil-1+1))+1;
		list_insert(ll, n);
	}
	
	//return NULL;
}



int main()
{
	list_t list;
	list_init(&list);

    get_num(&list);

	return 0;
}