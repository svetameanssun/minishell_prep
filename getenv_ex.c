#include <stdio.h>
#include <stdlib.h>
// basically, getenv does the same that my function 
// static char **find_path(char **envp) does!
// it encounters the line n the environment with the same word
// as in the argument you provide to the function, and  returns
// the string with everything that follows this "word" before \n

int main()
{
    char*path = getenv("PATH");
    //char*path = getenv("SHELL");
    //char*path = getenv("USER");
    // use any word in upper case from the result of the env command!
    if(path == NULL)
    {
        printf("NOT WORKED\n");
    }
    else 
    {
        printf("The PATH evironment variable:\n%s\n", path);
    }
}