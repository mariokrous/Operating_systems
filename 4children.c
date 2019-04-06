#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    int i, tmp;
    pid_t pid[4];
    tmp = 10000;
    //create 4 child-processes with the same father
    for (i=0;i<4;i++) {
        pid[i] = fork();
        if (pid[i] == 0) {
            //inside child process
            //with the usage of break statement, we are sure that
            // only father-process will fork
            break;
        }
    }

    if (pid[0] != 0 && pid[1] != 0 && pid[2] != 0 && pid[3] != 0) {
        //father-process
        // wait for child-processes 
        // print your id and your father's id
        printf("I'm the father [pid: %d, ppid: %d]\n",getpid(),getppid());
        for(i=0;i<4;i++) {
            wait(&tmp);
        }
    } else {
        //child-process
        //print your id and your father's id
        printf("I'm one of the children [pid: %d, ppid: %d]\n",getpid(),getppid());
    }

    return 0;
}
