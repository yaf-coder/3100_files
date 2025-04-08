#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];   // Line 1: Declare an array to hold the two pipe file descriptors.
    
    // Line 2: Create the pipe. pipefd[0] will be the read end, pipefd[1] the write end.
    if(pipe(pipefd) == -1) {
        perror("pipe failed");  // Line 3: Handle an error if pipe creation fails.
        exit(1);
    }
    
    // Line 4: Create a child process with fork().
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork failed");
        exit(1);
    }
    
    if(pid == 0) {  
        // Child process: This process will write data into the pipe.
        close(pipefd[0]);    // Line 5: Close the read end, since the child only writes.
        
        char *message = "Hello from child";  // Line 6: The message to send.
        // Line 7: Write the message to the write end of the pipe.
        if(write(pipefd[1], message, strlen(message) + 1) == -1) {
            perror("write failed");
            exit(1);
        }
        
        close(pipefd[1]);    // Line 8: Close the write end after writing.
        exit(0);             // Line 9: Exit the child process.
    } else {
        // Parent process: This process will read data from the pipe.
        close(pipefd[1]);    // Line 10: Close the write end; parent only reads.
        
        char buffer[100];    // Line 11: Buffer to store the read data.
        // Line 12: Read data from the read end of the pipe.
        if(read(pipefd[0], buffer, sizeof(buffer)) == -1) {
            perror("read failed");
            exit(1);
        }
        
        // Line 13: Print the message received from the child.
        printf("Parent received: %s\n", buffer);
        close(pipefd[0]);    // Line 14: Close the read end.
        
        wait(NULL);          // Line 15: Wait for the child process to finish.
    }
    
    return 0; // End of program.
}
