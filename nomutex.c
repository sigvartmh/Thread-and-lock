
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

typedef int bool;
enum { false, true };

bool running = 1;

int global = 0;
int global2 = 0;

void *print();
void *increment();

pthread_mutex_t mu;

int main(){
	pthread_t thread0;
	pthread_t thread1;
	
	pthread_create(&thread0, NULL, print, NULL);
	pthread_create(&thread1, NULL, increment, NULL);
	pthread_join(thread0, NULL);
}

void *print(){
	for(int i = 0; i<20; i++){
		printf("Number 1 is %d , Number 2 is %d \r\n", global, global2);
		usleep(1000000);
	}
	running = 0;
}

void *increment(){
	while(running){
	global++;
	global2 = global;
	}
}

