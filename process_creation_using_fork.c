#include <stdio.h>
#include <unistd.h>   // for fork()
#include <sys/types.h>

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if(pid < 0) {
        // Fork failed
        printf("Process creation failed!\n");
    }
    else if(pid == 0) {
        // Child Process
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else {
        // Parent Process
        printf("\n--- Parent Process ---\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}

// programiz: https://www.programiz.com/online-compiler/1Dn13UmUn0Acf
