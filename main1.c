#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

char** pl(char *line, char* delim){
  char ** args = calloc(7, sizeof(line));
  char * s = strdup(line);
  int i = 0;
  while(args[i] = strsep(&s, delim)){
    i++;
  }
  printf("sizeof args: %ld\n", sizeof(args));
  return args;
}

char**** execute(char *line){


}

void exec(char * entry){
  char ** args=pl(entry, " ");
  execvp(args[0],args);
  exit(0);
}

char * remove_n(char * entry){
  for(int i=0; i < strlen(entry); i++){
    if(entry[i] == '\n'){
      entry[i]='\0';
    }
  }
  return entry;
}

int main(){
  printf("Start \n");
  char input[100];
  int c = 1;
  while(c){
    int status = 0;
    printf("SMASH_SHELL#:");
    fgets(input, 100, stdin);

    strcpy(input, remove_n(input));

    if(strcmp(input, "exit") == 0){
      break;
    }

    int f = fork();
    wait(&status);
    if(!f){
      exec(input);
    }

    // char ** terms = calloc(7, sizeof(input));
    // char * s = strdup(input);
    // int i = 0;
    // while(terms[i] = strsep(&s, ";")){
    //   i++;
    // }
    // for(; i >= 0; i--){
    //   printf("%s\n", terms[i]);
    //   if(strcmp(terms[i], "exit") == 0){
    //     exit(0);
    //   }
    //   int f = fork();
    //   wait(&status);
    //   if(!f){
    //     exec(terms[i]);
    //   }
    // }
  }

  return 0;
}
