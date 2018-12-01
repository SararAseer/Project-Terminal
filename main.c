#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char** pl(char *line, char* delim){
  char ** args = calloc(7, sizeof(line));
  char * s = strdup(line);
  int i = 0;
  while(args[i] = strsep(&s, delim)){
    i++;
  }
  return args;
}

char**** execute(char *line){


}

int exec(char * entry){
  int status = 0;

  int f = fork();
  wait(&status);
  if(!f){
    char ** args=pl(entry, " ");
    execvp(args[0],args);
  }
}

int new_out(char* entry, char* file){
  int backup = dup(1);
  int file_desc = open(file ,O_WRONLY | O_CREAT | O_TRUNC, 0700);
  dup2(file_desc, 1);
  exec(entry);
  dup2(backup, 1);
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
    printf("SMASH_SHELL#:");
    fgets(input, 100, stdin);

    strcpy(input, remove_n(input));

    if(strcmp(input, "exit") == 0){
      break;
    }

    new_out("echo hello world", "foo");
    exec(input);

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
