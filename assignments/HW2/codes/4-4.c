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
  // p4
  // pid
  // search program
  printf("Search program with pid=%d\n", getpid());
  
  search();
  
  printf("Search program finished pid=%d\n", getpid());
}