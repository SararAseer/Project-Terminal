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

int exec(char * entry){
  char ** args=pl(entry);
  execvp(args[0],args);
  exit(0);
}

int main(){
  printf("Start \n");
  char input[100];
  int c = 1;
  while(c){
    fgets(input, 100, stdin);

    for(int i=0; i < strlen(input); i++){
      if(input[i]=='\n'){
        input[i]='\0';
      }
    }

    if(strcmp(input, "exit") == 0){
      break;
    }

    int f = fork();
    if(!f){
      exec(input);
    }
  }

  printf("Finish \n");
  return 0;
}
