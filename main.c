#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

char** parsebois(char *line){
  char ** args = calloc(1,25);
  char * s = strdup(line);
  int i = 0;
  while(args[i] = strsep(&s, " "))
    {
      i++;
    }
  return args;
}

int main(char *argv[],char argc){
  char input[500];
  printf("Start \n");
  scanf("%s", input);
  char ** commands=parsebois(input);
  printf("%s \n", commands[0]);
  printf("Finish \n");
  return 0;
}

