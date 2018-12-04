#ifndef FUNCS_H
#define FUNCS_H

char** pl(char *line, char* delim); //Parses the line base on the delimiter given so that it retuns an char**

int pip(char *first, char *second);

int exec(char * entry); //runs a command given a char*

int new_out(char* entry, char* file); // redirects a command into a file by changing the stdout

int new_in(char* entry, char* file); // redirects a file into the stdin

char * remove_n(char * entry); // removes a \n from the end of a string

void check(char **line);

#endif
