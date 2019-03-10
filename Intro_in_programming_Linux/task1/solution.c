#include "stdlib.h"
int stringStat(const char *string, size_t multiplier, int *count)
{
  unsigned int counter =0;
  while(*string!='\0')
  {
    counter++;
    string++;
  }

  *count +=1;
  return counter*multiplier;
}
