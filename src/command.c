
#include "command.h"


void process_command(char* words[], int len) {

    printf("%s", words[0]);

  if(strncmp(words[0], "timer", strlen("timer")) == 0) {
    // process timer command
    printf("Timer command\n");
  } else if(strncmp(words[0], "radio", strlen("radio")) == 0) {
    // process radio command
    printf("Radio command\n");
  } else if(strncmp(words[0], "command", strlen("command")) == 0) {
    // process command command
    printf("Command command\n");
  } else {
    printf("Invalid command\n");
  }

}
