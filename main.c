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


void pip(char *first, char *second){
 int p[2];
        if(pipe(p) == -1){
          printf("Pipe no work, thats so weird");
          exit(1);
        }

        if(fork() == 0){
            close(STDOUT_FILENO); 
            dup(p[1]);         
            close(p[0]);       
            close(p[1]);
	    char ** args1 =pl(first, " ");
            execvp(args1[0], args1);
            exit(1);
        }
        if(fork() == 0){
            close(STDIN_FILENO);   
            dup(p[0]);
            close(p[1]);       
            close(p[0]);
	    char ** args2 =pl(second, " ");
            execvp(args2[0], args2);
            exit(1);
        }

        close(p[0]);
        close(p[1]);
        wait(0);
        wait(0);

}

int exec(char * entry){
  int status = 0;
  int f = fork();
  wait(&status);
  if(!f){
    char ** args=pl(entry, " ");
    execvp(args[0],args);
    exit(0);
  }
}

int new_out(char* entry, char* file){
  int backup = dup(1);
  int file_desc = open(file ,O_WRONLY | O_CREAT | O_TRUNC, 0700);
  dup2(file_desc, 1);
  exec(entry);
  dup2(backup, 1);
}

int new_in(char* entry, char* file){
  int backup = dup(0);
  int file_desc = open(file ,O_RDONLY, 0700);
  dup2(file_desc, 0);
  exec(entry);
  dup2(backup, 0);
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
  char *entry="ls -l";
  char *back="wc -l";  
  pip(entry, back);
  return 0;
}
