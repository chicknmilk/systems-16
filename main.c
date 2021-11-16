#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
  printf("Parent process started\n");

  int pid = fork();
  if (!pid) {
    printf("Child process %d started\n", getpid());
  }
  int pid2;

  if (pid) {
    pid2 = fork();
    if (!pid2) {
      printf("Child process %d started\n", getpid());
    }
  }

  srand(time(getpid()));

  int time_sleep = rand() % 4 + 2;

  if (pid && pid2) {
    int status;
    int pid_stat = wait(&status);
    printf("Child process %d has finished in %d seconds\n", pid_stat, WEXITSTATUS(status));
    printf("Parent process ended\n");
    return 0;
  }

  sleep(time_sleep);
  printf("Child process %d finished sleeping\n", getpid());
  return time_sleep;

}