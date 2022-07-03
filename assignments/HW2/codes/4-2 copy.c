#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <stdio.h> 
#include <unistd.h>
#include<stdlib.h>
using namespace std;
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{ 
  // p2
  // pid
  printf("Search-Sort program with pid=%d\n", getpid());
  
  // Fork
  pid_t pid;
  pid = fork();
  
  if (pid < 0) { // fork failed
    printf("Fork failed\n");
  }
  else if (pid == 0) { // child process // p3
    printf("Entering sort program with pid=%d\n", getpid());
    // sort section
    // sort program args and execv
    char *args[] = {"sort", "c", "program", NULL};
    execv("./sort", args); // p5
  } else if (pid > 0) { // parent process // p2
    printf("Parent process with pid=%d\n", getpid());
    waitpid(pid, &returnStatus, 0); // wait for sort section to be completed (p3) 
    printf("Child completed."); // child (p3) process finished
    
    // p3 (sort) algorithm finished
    // create and execute p4 (search)
    // terminate p4 after searching completed
    pid_t pid2;
    pid2 = fork()
    
    if (pid2 < 0) { // fork failed
    printf("Fork failed\n");
    }
    else if (pid2 == 0) { // child process // p4
      printf("Entering search program with pid=%d\n", getpid());
      // search section
      // search program args and execv
      char *args[] = {"search", "c", "program", NULL};
      execv("./search", args); // p4
    } else if (pid2 > 0) { // parent process // p2
      printf("Parent process with pid=%d\n", getpid());
      waitpid(pid2, &returnStatus, 0); // waits for p4 to be completed
      printf("Child completed")
    }
  }
  
  printf("Search-Sort program finished with pid=%d\n", getpid());
  printf("Terminate\n");
} 