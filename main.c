#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

char** pl(char *line){
  char ** args = calloc(sizeof(line), sizeof(line));
  char * s = strdup(line);
  int i = 0;
  while(args[i] = strsep(&s, " ")){
    i++;
  }
  return args;
}

char**** execute(char *line){
 

}

int main(){
  char input[500];
  printf("Start \n");
  fgets(input, 500,stdin);
  for(int i=0; i < strlen(input); i++){
    if(input[i]=='\n'){
      input[i]='\0';
    }
  }
  int stat;
  char ** args=pl(input);
  int i = 0;
  if(fork()){
      execvp(args[0],args);
      return 1;
  }
  
  printf("Finish \n");
  return 0;
}

