#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

static unsigned int counter1 = 0;
static unsigned int counter2 = 0;

void handle_sigusr1(int sig)
{
  counter1++;
}

void handle_sigusr2(int sig)
{
  counter2++;
}

void handle_siterm(int sig)
{
  printf("%d %d\n",counter1,counter2);
  exit(1);
}

int main (int argc, char **argv)
{
  signal(SIGUSR1, handle_sigusr1);
  signal(SIGUSR2, handle_sigusr2);
  signal(SIGTERM, handle_siterm);

  while (1) sleep(1);
  return 0;
}
