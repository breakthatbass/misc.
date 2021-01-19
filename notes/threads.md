# threads and locks

### thread and locks table of contents
#### threads
1. [threads](#threads)
1. [locks](#locks)
2. [thread safe linked list example](#linkedlist)

Threads and locks are both done with a series of functions from the `<pthread.h>` library.

## threads
Threads are similar to processes except threads share the same address space and are able to access the same data. Threads also have their own stacks within the address space of the program.  They can be useful for designating tasks to seperate processors for faster programs.

**basic thread creation**
```C
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

void *mythread(void *arg)
{
    printf("%s\n", (char *)arg);
    return NULL;
}

int main()
{
    pthread_t p1, p2;
    int rc;

    // create and error check threads
    rc = pthread_create(&p1, NULL, mythread, "A");
        assert(rc == 0);
    rc = pthread_create(&p2, NULL, mythread, "B");
        assert(rc == 0);

    // join waits for the threads to finish
    rc = pthread_join(&p1, NULL);
        assert(rc == 0);
    rc = pthread_join(&p2, NULL);
        assert(rc == 0);

    return 0;
}


```

## locks
Locks are used around sections of code called 'critical sections', meaning that only one thread at a time is allowed to access that block. Without locks, different threads will access blocks of code together and cause the results to be wrong.  

A lock around a critical section would look something like this:
```C
pthread_mutex_t lock; 
// ...
pthread_mutex_lock(&lock);  // lock the gate
x++;   // critical section
pthread_mutex_ulock(&lock); // unlock the gate
```
The program below shows how threads and locks can be created and used. A thread is created by declaring a varible with `pthread_t` and then using the `pthread_create` function. By passing in a function pointer to `pthread_create` we create the instructions for what we want to thread to do. In this case, we want each thread to add 1 to the global variable `counter` 10 million times. With locks the result is correct with `20000000`. However, without the locks `counter` ends up being smaller and also a different amount every time.
```C
#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>

static volatile int counter = 0;

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *mythread(void *arg)
{
	printf("%s: begin\n", (char *) arg);
	int i;
	for (i = 0; i < 1e7; i++) {
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	}

	printf("%s: done\n", (char *)arg);
	return NULL;
}

int main()
{
	pthread_t p1, p2;
	printf("main: begin (counter = %d)\n", counter);

        // parameters are 1. the thread variable
        // 2. any modifications, usually NULL
        // 3. function pointer (what the thread will be doing)
        // 4. argument for function pointer (void *)
	pthread_create(&p1, NULL, mythread, "A");
	pthread_create(&p2, NULL, mythread, "B");

        // pthread_join is basically wait() for threads
        // it makes the main process wait for the threads to finish
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	printf("main: done with both (counter = %d)\n", counter);
	return 0;
}
```

## linkedlist
This is an example of a basic linked list that makes use of locks to make it thread safe. It's just a normal list but with locks around any place where the list gets updated.
```C
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

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
	node_t *new = malloc(sizeof(node_t));
	if (new == NULL) {
		perror("malloc");
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
			rv = 0;
			break;
		}
		cur = cur->next;
	}
	pthread_mutex_unlock(&ll->lock);
	return rv;	// not found
}
```
