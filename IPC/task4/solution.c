#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdlib.h>

int main (int argc, char **argv)
{
  int addr1 = atoi(argv[1]);
  int addr2 = atoi(argv[2]);

  int ShmID1 = shmget(addr1,1000, IPC_CREAT | 0600);
  int ShmID2 = shmget(addr2,1000, IPC_CREAT | 0600);

  int ShmIDout = shmget((key_t) 54321 ,1000, IPC_CREAT | 0666);

  int *sumShared1=(int*)shmat(ShmID1,NULL,0);
  int *sumShared2=(int*)shmat(ShmID2,NULL,0);
  int *sumShared3=(int*)shmat(ShmIDout,NULL,0);

  unsigned int i = 0;
  for(i=0;i<100;i++)
  {
    sumShared3[i] = sumShared1[i] + sumShared2[i];
  }

  printf("%i\n",54321);
  shmdt(sumShared1);
  shmdt(sumShared2);
  shmdt(sumShared3);

  return 0;
}
