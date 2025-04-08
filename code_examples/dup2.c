#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    // Line 1: Open or create the file "output.txt" for writing.
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(fd < 0) {             // Line 2: Check if opening the file failed.
        perror("open failed");
        exit(1);
    }
    
    // Line 3: Duplicate fd onto STDOUT_FILENO (file descriptor 1).
    // This causes any writes to standard output to go to "output.txt".
    if(dup2(fd, STDOUT_FILENO) < 0) {   
        perror("dup2 failed"); // Line 4: Print error if dup2 fails.
        exit(1);
    }
    
    // Line 5: This output, originally destined for the terminal (stdout),
    // is redirected to the file "output.txt".
    printf("This will go to output.txt file instead of the terminal\n");
    
    // Line 6: Close the original file descriptor; standard output remains redirected.
    close(fd);
    
    return 0;
}
