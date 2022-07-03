#include <stdio.h> 
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{ 
  // p2
  // pid
  printf("Search-Sort program with pid=%d\n", getpid());
  
  // fork
  // p3 (sort) algorithm
  pid_t pid;
  pid = fork();
  pid = fork();
  // p4 (search) algorithm
  pid_t pid2;
  pid2 = fork()

  if (pid2 < 0) { // fork failed p3
    printf("Fork 1 failed\n");
  }
  if (pid < 0) { // fork failed p4
    printf("Fork 2 failed\n");
  }
  
  // p3 decision tree
  if (pid == 0) { // child process // p3
    printf("Entering sort program with pid=%d\n", getpid());
    // sort section
    // sort program args and execv
    char *args[] = {"sort", "c", "program", NULL};
    execv("./sort", args); // p5
  } else if (pid > 0) { // parent process // p2
    printf("Parent process with pid=%d\n", getpid());
    waitpid(pid, &returnStatus, 0); // wait for sort section to be completed (p3) 
    // p3 is finished. kill p4
    kill(pid, SIGKILL);
    printf("Child completed"); // child (p3) process finished
  }

  // p4 decision tree
  if (pid2 == 0) { // child process // p4
    // p4
    // pid
    // search program
    printf("Search section with pid=%d\n", getpid());
    search();
    printf("Search section finished pid=%d\n", getpid());

  } else if (pid2 > 0) { // parent process // p2
    printf("Parent process with pid=%d\n", getpid());
    waitpid(pid2, &returnStatus, 0); // waits for p4 to be completed
    printf("Child completed")
  }
  
  printf("Search-Sort program finished with pid=%d\n", getpid());
  printf("Terminate\n");
} 