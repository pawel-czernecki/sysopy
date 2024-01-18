#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello, I'm system program!\n");
    getchar(); // Wait for user input before proceeding with the system command

    // Run the system command "ls -al /var/log/"
    int result = system("ls -al /var/log/");

    if (result == -1) {
        perror("Error in system");
        return 1;
    }

    return 0;
}