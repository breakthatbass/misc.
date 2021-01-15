#include <stdio.h>
#include <pthread.h>
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
	pthread_mutex_t lock;
} list_t;


// initiate a list and lock
void list_init(list_t *ll)
{
	ll->head = NULL;
	pthread_mutex_init(&ll->lock, NULL);
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

	pthread_mutex_lock(&ll->lock);
	new->next = ll->head;
	ll->head = new;
	pthread_mutex_unlock(&ll->lock);
}


int list_lookup(list_t *ll, int key)
{
	int rv = -1;
	pthread_mutex_lock(&ll->lock);
	node_t *cur = ll->head;
	while(cur) {
		if (cur->key == key) {
			// pthread_mutex_unlock(&ll->lock);
			rv = 0;
			break;
		}
		cur = cur->next;
	}
	pthread_mutex_unlock(&ll->lock);
	return rv;	// not found
}


// get_num: get random num and add it to list
void *get_num(void *arg)
{
	int ceil = 999;

	srand(time(0));
	for (int i = 0; i < 30000000; i++) {
		int n = (rand() % (ceil-1+1))+1;
		list_insert(arg, n);
	}
	
	return NULL;
}



int main()
{
	list_t list;
	list_init(&list);
	pthread_t p1, p2, p3;

	pthread_create(&p1, NULL, get_num, &list);
	pthread_create(&p2, NULL, get_num, &list);
	pthread_create(&p3, NULL, get_num, &list);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);

	return 0;
}