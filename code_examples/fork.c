#include <stdio.h>    // Standard I/O routines
#include <stdlib.h>   // For exit()
#include <unistd.h>   // For fork() and getpid()
#include <sys/wait.h> // For wait()

int main() {
    // Create a new process using fork()
    pid_t pid = fork();   // Line 1

    if (pid < 0) {        // Line 2
        perror("fork failed"); // Line 3: Print error if fork fails.
        exit(1);          // Line 4: Terminate with error code.
    }
    
    if (pid == 0) {       // Line 5: Child process block (fork returns 0 in child).
        printf("Hello from child process, PID = %d\n", getpid()); // Line 6
        exit(0);          // Line 7: End the child process.
    } else {              // Line 8: Parent process block (fork returns child's PID).
        printf("Hello from parent process, PID = %d, child's PID = %d\n", getpid(), pid); // Line 9
        wait(NULL);       // Line 10: Parent waits for the child to terminate.
    }
    return 0;             // Line 11: Exit the parent process.
}
