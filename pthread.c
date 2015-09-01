#include<stdio.h>
#include<pthread.h>

int global = 0;
void *print();

int main(){
	pthread_t thread0;
	pthread_t thread1;
	pthread_create(&thread0, NULL, print, NULL);
	pthread_create(&thread1, NULL, print, NULL);
	pthread_join(thread0, NULL);
	return 0;
}

void *print(){
	int local = 0;
	for(int i = 0; i < 10; i++){
		local++; global++;
	}
	printf("Local: %d, Global: %d\r\n", local, global);
}

