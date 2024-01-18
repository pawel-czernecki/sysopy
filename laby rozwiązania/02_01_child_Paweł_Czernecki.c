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
  }

  getchar();

  return 0;
}