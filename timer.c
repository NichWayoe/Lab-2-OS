/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flag = 0;
int seconds = 0;

void alarmSignalHandler(int signum)
{ //signal handler
  flag = 1;
}

void exitSignalHandler(int sigint) {
  printf("Your Program took %d seconds \n",seconds);
  exit(1);
}

int main(int argc, char * argv[]) {
  printf("Your program is running...\n");
  signal(SIGALRM, alarmSignalHandler);
  signal(SIGINT, exitSignalHandler);
  while (1) {
     alarm(1);
     while(flag == 0){}; 
     seconds += 1;
     flag = 0;
  }
  return 0;
}