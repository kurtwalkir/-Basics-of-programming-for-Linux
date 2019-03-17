#include "stdlib.h"
#include "dlfcn.h"

int (*someSecretFunctionPrototype)(int);

int main(int argc , char **argv)
{
  if (argc<3)
  {
     printf("Error numbers of input arg!\n");
     return 0;
  }

  void *handle = NULL;
  handle = dlopen(argv[1],RTLD_LAZY);

  if(!handle)
  {
    printf("Shared library did not open!\n");
  }

  someSecretFunctionPrototype = (int(*)(int))dlsym (handle, argv[2]);
  int inputVal = atoi (argv[3]);
  int res = someSecretFunctionPrototype(inputVal);
  printf("%d\n", res);

  return 0;
}
