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
  // p1
  // pid
  printf("Main program with pid=%d\n", getpid());
  
  // init program args and execv
  char *args[] = {"search-sort", "c", "program", NULL};
  execv("./search-sort", args); // p2
  
  printf("Back in main program pid=%d\n", getpid())
} 
