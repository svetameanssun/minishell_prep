#ifndef READLINE_EX_H
#define READLINE_EX_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);

#endif