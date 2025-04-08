#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>   // For open()

int main() {
    // Line 1: Open a file "test.txt" with write-only access, create/truncate it.
    int fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {             // Line 2: Check for errors opening the file.
        perror("open failed");
        exit(1);
    }
    
    // Line 3: Duplicate the file descriptor 'fd'.
    int newfd = dup(fd);      
    if (newfd < 0) {          // Line 4: Check if dup() failed.
        perror("dup failed");
        exit(1);
    }
    
    // Line 5: Write to the file using the original file descriptor.
    write(fd, "Hello using fd\n", 16);
    
    // Line 6: Write to the file using the new, duplicated descriptor.
    write(newfd, "Hello using newfd\n", 19);
    
    // Line 7: Close both file descriptors.
    close(fd);
    close(newfd);
    
    return 0; // End of program.
}
