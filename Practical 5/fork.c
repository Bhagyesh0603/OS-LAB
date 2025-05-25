//Program to implement fork system call
//Bhumika Jadhav (SY_B_10)

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    } 
    else if (pid == 0) {
        printf("Child process\n");
        printf("Child PID      : %d\n", getpid());
        printf("Parent's PID   : %d\n", getppid());
    } 
    else {
        printf("Parent process\n");
        printf("Parent PID     : %d\n", getpid());
        printf("Child's PID    : %d\n", pid);

	//wait(NULL);
        waitpid(pid, NULL, 0);
        printf("Parent process terminated\n");
    }

    return 0;
}



/* output 

Parent process
Parent PID     : 3900
Child's PID    : 3901
Child process
Child PID      : 3901
Parent's PID   : 3900
Parent process terminated

*/
