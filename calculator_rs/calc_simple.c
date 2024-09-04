#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>

// Dictionary
//# define PLUS 1
//# define  DIGIT 2

enum e_types {
	PLUS,
	DIGIT
};

typedef struct s_token
{
	//s_token * pre;
	int type;
	int value;
	struct s_token *next;

}	t_token;

int check_args(char c, t_token *my_token)
{
	printf("Character: %c\n", c);
	if (c >= '0'  && c <= '9')
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
	return(0);
}

int check_one_arg(char *str, t_token *my_token)
{
	int ctr = 0;

	t_token *save_token;
	save_token = my_token;
	while (str[ctr] != '\0')
	{
		if (check_args(str[ctr], my_token) != 1)
		{
			my_token->next = (t_token*)malloc(sizeof(t_token));
			my_token = my_token->next;
		}
		ctr++;
	}

}


void fill_token_list(int argc, char **argv, t_token **token_list)
{
	
	t_token *save_token;
	int i;

	*token_list = (t_token*)malloc(sizeof(t_token));
	save_token = *token_list;
	if (argc == 2)
	{
		check_one_arg(argv[1], save_token);
	}
	else
	{
		
		i = 1;
		while(i < argc)
		{
			check_args(argv[i][0], save_token);
			save_token->next = (t_token*)malloc(sizeof(t_token));
			save_token = save_token->next;
			i++;
		}
		save_token->next = NULL;
	}
}

void manage_error(char *msg)
{
	printf("Error: %s\n", msg);
	exit(-1);
}

int sum_args(t_token *token_list)
{
	int res;
	int status;

	if (token_list == NULL)
		return 0;

	status = token_list->type;
	if (status != DIGIT)
		manage_error("Wrong input");
	res = token_list->value;

	token_list = token_list->next;
	while(token_list != NULL)
	{
		if ((status == DIGIT && token_list->type != PLUS) || (status == PLUS && token_list->type != DIGIT)) {
			manage_error("Wrong input");
		}
		status = token_list->type;
		if (status == DIGIT) {
			res += token_list->value;
		}
		token_list = token_list->next;
	}
	return res;
}
void print_list(t_token *node)
{
	while (node)
	{
		printf("type: %d, value> %d\n", node->type, node->value);
		node = node->next;
	}
}


int main(int argc, char **argv)
{
	t_token *token_list;

	fill_token_list(argc, argv, &token_list);
	print_list(token_list);
	printf("Result = %d\n", sum_args(token_list));



	return(0);
}