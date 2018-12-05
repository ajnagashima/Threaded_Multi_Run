#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// The function used by the threads to make system calls
void *sysCall(void *cmd){
    system(cmd);
    return NULL;
}

// Print usage and exit
void usage(){
    fprintf(stderr, "tmr <num> <cmd>");
    exit(1);
}

int main(int argc, char *argv[]){
    //Check to see if number of args is correct
    if(argc != 3){
        usage();
    }

    int num = atoi(argv[1]);
    for(int i = 0; i < num; i++){
        pthread_t thread;
        pthread_create(&thread, NULL, sysCall, argv[2]);
    }
    pthread_exit(NULL);
    return 0;
}
