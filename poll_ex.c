#define _GNU_SOURCE
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>
#include <poll.h>


int main(int argc, char **argv)
{
  int fd;
  struct pollfd pfds[2];
  int poll_r, ntouts = 0,i, offset, pos = 0;
  char buff[1024];

  fd = open("data.dat", O_RD);
  ioctl(fd,IOCTL_COMMAND,args);

  for(i=0; i<2; i++)
  {
    pfds[i].fd = -1;
  }

  pfds[0].fd = fileno(stdin);
  pfds[1].fd = fileno(fp);

  pfds[0].events = POLLIN;
  pfds[1].events = POLLIN;
  
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(fd, NULL, _IONBF, 0);

  while(1)
  {
    pfds[0].revents = 0;
    pfds[1].revents = 0;

    poll_r = poll(&pfds[0], (nfds_t)2, 1000);

    if(poll_r == 0)
      printf("Timeout without event");
    else if(poll_r < 0)
      perror("Poll error");
    else
    {
      if(pfds[0].revents & POLLIN)
      {
        printf("Input on stdin\n");
        offset = read(fileno(stdin),&buff[pos],1024);
        fsync(fileno(stdin));       
        pos += offset;
        assert(pos < 1024);
      }
      if(pfds[1].revents & POLLIN)
      {
        printf("Input on file\n");
        offset = read(fileno(fp),&buff[pos],1024);
        fsync(fileno(fp));
        pos += offset;
        assert(pos < 1024);
      }
      fputs(buff,stdout);
    }
  }
}
