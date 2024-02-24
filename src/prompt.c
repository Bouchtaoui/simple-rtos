#include "prompt.h"
#include "command.h"

#define MAX_PROMPT_SIZE 1024

void print_array(char* arr[], int len) {
  for(int i=0; i<len; i++) {
    printf("%s ", arr[i]);
  }
}

void process_prompt(char* arr[], int len) {
  process_command(arr, len);
}
void run_prompt(){

  // set buffer with enough space for the input
  char input[MAX_PROMPT_SIZE];
  // set an array to hold the tokens
  char *tokens[16];

  // print prompt
  printf("Enter command: ");

  // read input
  fgets(input, MAX_PROMPT_SIZE, stdin);

  // tokenize input
  int count = 0;
  char* token = strtok(input, " ");
  while (token) {
    tokens[count++] = token;
    token = strtok(NULL, " ");
  }

  // print tokens
//   print_array(tokens, count);
  process_prompt(tokens, count);

}
