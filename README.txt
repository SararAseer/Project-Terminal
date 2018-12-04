DCSA
by Derek Chan and Sarar Aseer

Features:
	Forks and executes commands!
	Parses multiple commands on one line!
  Pipes!
	Redirects using >, <!

Attempted:
	The following did not end up working. and the code deleted
	Could not get multiple redirects to work
	tried to replace ~/ with home directory but could not think of a way even using getcwd()

Bugs:
	Cannot have spaces between a command/file and ;,>,<,|
  multiple redirects do not work :(

Files & Function Headers:
funcs.c
	Handles all the helper functions
	/*======== int remove_n() ==========
	Inputs:  char *entry
	Returns: char * of an entry without the \n

  Removes the \n read in from stdin or any file
	====================*/

	/*======== char ** pl() ==========
	Inputs:  char *line, char* delim
	Returns: Array of strings where each entry is a token
	separated by delim

	If line contains multiple tokens separated by delim, this
	function will put each token into an array of strings
	====================*/

	/*======== int exec() ==========
	Inputs:  char * entry
	Returns: 0 if successfully ran an entry

	executes a given command by forking a child
  and running the command on the child
	====================*/

  /*======== int new_out() ==========
	Inputs:  char * entry
	Returns: 0 if successfully ran an entry

	redirects a command into a cleared file by changing the stdout
	====================*/

  /*======== int pip() ==========
	Inputs:  
	Returns:


	====================*/

  /*======== int check() ==========
	Inputs:
	Returns:


	====================*/


main.c
	Handles the cd and exit commands and checks for <,>,;,| in an entry.
