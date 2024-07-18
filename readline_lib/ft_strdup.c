/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:57:05 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/17 17:01:13 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_ex.h"

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*res;
	int				i;

	len = (unsigned int)ft_strlen(s);
	i = 0;
	res = (char *)malloc(len * sizeof(char) + 1);
	if (res == 0)
		return (0);
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
