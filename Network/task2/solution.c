#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 5120

int main (int argc, char **argv)
{
  int sockfd;
  char buffer[MAXLINE];

  struct sockaddr_in servaddr;
  // Creating socket file descriptor
  if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      perror("socket creation failed");
      exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));

  // Filling server information
  servaddr.sin_family    = AF_INET; // IPv4
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(atoi(argv[1]));

  // Bind the socket with the server address
  if ( bind(sockfd, (const struct sockaddr *)&servaddr,
          sizeof(servaddr)) < 0 )
  {
      perror("bind failed");
      exit(EXIT_FAILURE);
  }

  int len, n;

  while (1) {
  memset(buffer,0,sizeof(buffer));
  n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &servaddr,&len);
  if (strncmp(buffer, "OFF\n", 4) == 0) break;
  else printf("%s\n", buffer);
  }

  return 0;
}
