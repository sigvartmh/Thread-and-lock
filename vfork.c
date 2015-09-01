#include<unistd.h>
#include<stdio.h>

int global = 0;

int main(){
    int local = 0;
    pid_t cPID = vfork();
    for(int i = 0; i < 10; i++){
        global++;
        local++;
    }
    printf("Local : %d, Global %d \r\n", local, global);
    return 0;
}
