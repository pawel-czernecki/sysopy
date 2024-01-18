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

    getchar();

    pid_t grandchild_pid = fork();
    if (grandchild_pid == 0) {
        // grandChild
        printf("Grandchild PID (soruce-GRANDCHILD): %d\n", getpid());
        printf("Child PID (source-GRANDCHILD): %d\n", getppid());

        kill(getpid());
        return 0;
    }

  } else {
    // Parent
    printf("Parent PID (source-PARENT): %d\n", getpid());
    sleep(4);
  }

  return 0;
}