#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>

// Intead of macros we can use structure enum.
// What is the difference?
// MACROS                               | ENUM
// -------------------------------------|---------------------------------------|
// Macros are processed before			| ???????????????????????               |
// compilation in pre-processing stage  |  ??????????????????????               |
// -------------------------------------|---------------------------------------|
// If you use #define VAR 2, you assign | In the enum structes all the values   |
// the variable by yourself, no order,  | are are assigned an int (?) in order. |
// you can choose random numbers  		|                                       |
// -------------------------------------|---------------------------------------|
// Macros can be changed during			| Enum structure cannot be modified     |
// compilation and it might affect		| before compilation                    |
// the final result						|                                       |
//--------------------------------------|---------------------------------------|

enum e_types
{
	PLUS,
	DIGIT
};


typedef struct s_token
{
	int type;
	int value;
	struct s_token * next;

} t_token;

void manage_error(char *msg)
{
	printf("Error: %s\n", msg);
	exit(-1);
}

int fill_with_tokens(char c, t_token *my_token)
{
	if (c >= '0' && c <= '9')
	{
		my_token->type = DIGIT;
		my_token->value = atoi(&c);
		
	}
	if (c == '+')
	{
		my_token->type = PLUS;
		my_token->value = PLUS;
	}
	else
		return (1);
	return (0);

}

int fill_one_token(char *str, t_token *my_token)
{
	int ctr;

	ctr = 0;
	while(str[ctr] != '\0')
	{
		if (fill_with_tokens(str[ctr], my_token) != 1)
		{
			my_token->next = (t_token*)malloc(sizeof(t_token));
			my_token = my_token->next;
		}
		ctr++;
	}
	return(0);

}

void fill_token_list(int argc, char ** argv, t_token ** token_list)
{
	int i;
	t_token * save_token;

	i = 1;
	save_token = *token_list;
	if (argc == 2)
	{
		fill_one_token(argv[1], save_token);
	}
	else
	{
		while (i < argc)
		{
			fill_with_tokens(argv[i][0],save_token);
			save_token->next = (t_token*)malloc(sizeof(t_token));
			save_token = save_token->next;
			i++;
		}
		save_token->next = NULL;
	}
}

int sum_args(t_token *token)
{
	int res;

	printf("%d\n", token->type);
	printf("%d\n", DIGIT);
	if ( token->type!= DIGIT)
	{
		manage_error("WRONG INPUT");
	}
	res = token->value;

	token = token->next;
	while(token != NULL)
	{
		if ((token->type == DIGIT && token->type != PLUS)
			|| (token->type == PLUS && token->type != DIGIT))
		{
			manage_error("Wrong Input");
		}
		if(token->type == DIGIT)
		{
			res = res + token->value;
		}
		token = token->next;
	}
	return (res);
}

void print_list(t_token *node)
{
	while (node)
	{
		printf("type: %d, value> %d\n", node->type, node->value);
		node = node->next;
	}
}

int main(int argc, char ** argv)
{
	int result;
	t_token * token_list;
	token_list = (t_token*)malloc(sizeof(t_token));
	if (token_list == NULL)
		return(1);

	fill_token_list(argc, argv, &token_list);
	print_list(token_list);
	result = sum_args(token_list);
	printf("The result: %d\n", result);

	free(token_list);
	return (0);
}