#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>


void run_select() {
  fd_set readfds;
  struct timeval tv;
  int nfds = 2;

  while(1) {
    // Reset file descriptor set
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Add file descriptors to set

    // Set timeout
    tv.tv_sec = 2; // 2 seconds
    tv.tv_usec = 0;

    int rv = select(nfds, &readfds, NULL, NULL, &tv);

    if(rv == -1) {
      // Select error
      perror("select");
      break;
    } else if(rv == 0) {
      // Timeout occurred
      printf("Timeout!\n");
    } else {
      // File descriptors ready in readfds
      // Process input
      if(FD_ISSET(STDIN_FILENO, &readfds)) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        printf("Input: %s", input);
      }
    }
  }
}
