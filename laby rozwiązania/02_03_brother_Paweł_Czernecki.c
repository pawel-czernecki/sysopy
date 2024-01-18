#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();
  printf("PID: %d\n", pid);
  getchar();

  pid_t child_pid = fork();
  if (child_pid == 0) {
    // Child
    printf("Child PID (soruce-CHILD): %d\n", getpid());
    printf("Parent PID (source-CHILD): %d\n", getppid());

  } else {
    // Parent
    printf("Parent PID (source-PARENT): %d\n", getpid());
    //return 0;
    getchar();
    pid_t brother_pid = fork();
    if (brother_pid == 0) {
        // Child
        printf("Brother PID (soruce-BROTHER): %d\n", getpid());
        printf("Parent PID (source-BROTHER): %d\n", getppid());

        kill(getpid());
    }
    else{
        sleep(5);
    }

  }
  return 0;
}