#ifndef MAIN_H
#define MAIN_H

char** pl(char *line, char* delim);

void pip(char *first, char *second);

int exec(char * entry);

int new_out(char* entry, char* file);

int new_in(char* entry, char* file);

char * remove_n(char * entry);

void check(char **line);

#endif
