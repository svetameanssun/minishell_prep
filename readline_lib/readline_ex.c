
#include "readline_ex.h"

/**
 * @brief 	-> char *str;
 * 			readline("Write a line to read: ")
 * 			reads a line from a terminal , and returns
 * 			a pointer to a string with this line saved.
 * 			It saves this line in memory with help of malloc(3),
 * 			thus IT IS CRUCIAL TO FREE this string after using it.
 * 			Readline() reads the whoe line, doesn't matter the spaces.
 *
 * 			add_history(str) saves the str in the history,
 * 			and while the program is running you can access the histoty of the commands
 * 			by using keys up/down
 *			
			-> char text[100];
 * 			scanf("%s", text) saves a string in a buffer of already reserved memory.
			Scan() scans a line till a space is enountered.
 * 		 	
 * 
 * 			
 */
/*int main() {
    char *input;

    // Initialize Readline
    rl_initialize();

    // Simulate reading a line of input
    input = readline("Prompt> ");
    
    // Replace the current line with a new line of text
    rl_replace_line("This is the new line", 1);
    
    // Force the display to update
    rl_redisplay();
    
    // Clean up
    free(input);

    return 0;
}*/
/*int main()
{
	char *repl = "replacement!";
	char *str;
	str = readline("Write '+' \n");
	printf("\nThe line you wrote, that was saved in rl_line_buffer: %s\n", rl_line_buffer);
	rl_replace_line(repl, 0);
	rl_redisplay();
	int i = 0;
	sleep(1);
	//printf("\nThe line that replaced your line in rl_line_buffer: %s\n", rl_line_buffer);
}*/
int main()
{
	char *str;
	char str1[100] = " - save in history";
	char str2[100] = " - and this";
	char * repl = "replacement!";
	char *str3;
	char *str4;
	int i = 0;
	

	while(1)
	{
		
		str = readline("\nIntroduce text: ");
		if (str == NULL)
			exit(0);
		//str3 = ft_strjoin(ft_itoa(i), str1);
		//str4 = ft_strjoin(ft_itoa(i), str2);
		//add_history(str);
		//add_history(str3);
		//add_history(str4);
		//str = readline("\nIntroduce more text: ");
		rl_replace_line(repl, 0);
		
		//printf("New input: %s\n", rl_line_buffer);
		//printf("-> %s <-", str);
		
		i++;
		rl_on_new_line();
		rl_redisplay();
		free(str);
		//free(str3);
		//free(str4);
	}
	printf("Historial antes de limpiar: %d\n", history_length);
	rl_clear_history();
	printf("Historial antes de limpiar: %d\n", history_length);

	//char text[100];
	//printf("Scan this line: ");
	//scanf("%s", text);
	//printf("-> %s <-\n", text);
	
}

/*int main()
{
    char *str;

    while (1)
	{
        // Prompt the user for input
        str = readline("Enter a command: ");
        
        // Check if input is not NULL
        if (str)
		{
            // If the input is "exit", break the loop
            if (strcmp(str, "exit") == 0)
			{
                free(str);
                break;
            }
            
            // Add the input to the history list
            add_history(str);

            // Print the input to show it was captured
            printf("You entered: %s\n", str);

            // Free the allocated memory
            free(str);
        }
		else
		{
            printf("No input received.\n");
        }
    }

    return 0;
}*/
