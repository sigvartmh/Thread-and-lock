#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int global = 0;
void *print();
sem_t semaphore;

int main(){
	pthread_t thread0;
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;
	
	sem_init(&semaphore, 5, 3);	
	pthread_create(&thread0, NULL, print, NULL);
	pthread_create(&thread1, NULL, print, NULL);
	pthread_create(&thread2, NULL, print, NULL);
	pthread_create(&thread3, NULL, print, NULL);
	pthread_create(&thread4, NULL, print, NULL);
	for(int i = 0; i<4; i++){
		printf("Global: %d\r\n", global);
		usleep(100000);
	}
	pthread_join(thread0, NULL);
	return 0;
}

void *print(){
	sem_wait(&semaphore);
	int local = 0;
	sem_getvalue(&semaphore, &local);
	global++;
	printf("Sem: %d\r\n", local);
	usleep(1000);
	sem_post(&semaphore);
}

