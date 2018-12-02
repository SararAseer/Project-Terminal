#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "funcs.h"

int main(){
  printf("Start \n");
  char input[100];

  while(1){
    printf("SHELL#:");
    fgets(input, 500,stdin);
    remove_n(input);

    if(strcmp(input, "exit") == 0){
      exit(0);
    }

    char ** args=pl(input, " ");

    if(strcmp(args[0], "cd") == 0){
      chdir(args[1]);
    }
    else{
      char **s1=pl(input, ";");
      check(s1);
      int i=0;
      int x=0;
      while(s1[i]){
        while(s1[i][x]){
          if(s1[i][x]=='<'||s1[i][x]=='>'||s1[i][x]=='|'){
    	s1[i]="skip";
    	break;
          }
          x++;
        }
        i++;
      }
      i=0;
      while(s1[i]){
        if(s1[i]!="skip"){
          exec(s1[i]);
        }
        i++;
      }
    }
  }
  return 0;
}
