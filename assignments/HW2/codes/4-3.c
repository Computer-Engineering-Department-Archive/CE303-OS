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
  // p5
  // pid
  // sort program
  printf("Sort program with pid=%d\n", getpid());
  
  sort();
  
  printf("Sort program finished pid=%d\n", getpid());
} 
