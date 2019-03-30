#include "stdio.h"

int main (int argc, char **argv)
{

  char nameStr[255];
  sprintf(nameStr,"%s %s",argv[1],argv[2]);

  FILE *oPipe;
  oPipe=popen(nameStr,"r");
  unsigned int counter = 0;
  int c;

  do
  {
    c = fgetc(oPipe);
    if (c == '0') counter++;
  } while (c != EOF);

  printf("%d\n", counter);
  pclose(oPipe);
}
