#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>

static volatile int counter = 0;

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *mythread(void *arg)
{
	printf("%s: being\n", (char *) arg);
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

	pthread_create(&p1, NULL, mythread, "A");
	pthread_create(&p2, NULL, mythread, "B");

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	printf("main: done with both (counter = %d)\n", counter);
	return 0;
}
