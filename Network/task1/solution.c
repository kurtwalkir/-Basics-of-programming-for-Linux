#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main (int argc, char **argv)
{
  struct hostent *host_entry;

  host_entry = gethostbyname(argv[1]);
  unsigned int i = 0;
  while (NULL!=host_entry->h_addr_list[i]) {
    printf("%s\n", inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[i])));
    i++;
  }
}
