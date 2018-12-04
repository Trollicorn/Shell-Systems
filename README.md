# Shell-Systems (Carapace)
by Mohammed Uddin

### Features
  * "make" gets everything ready and "make run" runs the shell
  * Can give arguments to commands
  * Can give multiple commands seperated by semicolon
  * Spaces in the beginning don't matter (other whitespace probably matters)
  * Spaces at the end don't matter (other whitespace probably matters)
  * Multiple spaces between arguments don't matter (other whitespace probably matters)
  * cd and exit work
  * cd without any arguments works
  * Redirect using '<', '>', and '>>' works
  * Multiple redirections SHOULD work (I may have missed some test cases)
  * Piping works (one pipe per command seperated by semicolon)
  * Error messages when command not found.

### Attempted
  * Tried to catch SIGINT signal to stop Ctrl + C, but that messed with how the child processes were exiting and I didn't have enough time to finish it.
  * Tried to make quotation marks temporarily stop parsing until another quotation mark was reached, but did not finish it.
  * Tried to implement redirect using '2>', '2>>', '&>', and '&>>', but didn't finish.

### Bugs
  * Compiling lobster.c (or using make) prints out a warning which I never got around to fixing.
  * One pipe only per command
  * Spaces inside quotations are parsed through
  * Semicolons inside quotations are parsed through
  * Multiple semicolons could be right next to each other like ";;;" but would be treated as one semicolon
  * A semicolon as the first thing in the input will not return an error
  * If command isn't found, nothing is returned
  * Virtual environment is not shown when activated
  * Ctrl + C closes the shell

### Files and Function Headers
* pargs.c
  * Does parsing stuff
  * char ** pargs (char * line, char * delim);
    * Input:
      * char * line is the line to be parsed through
      * char * delim is the delimiter that will be used to parse through line
    * Return:
      * Array of strings with each string being the parts of line seperated by delim
* lobster.c
  * Does everything else
  * void prompt();
    * Prints out the command line prompt
  * int lobster();
    * One iteration of the shell. Takes input given to the shell and makes it do the stuff it's supposed to do.
* beetle.c
  * The loop file
    * int main();
      * Basically calls lobster() forever until told to exit.
    
