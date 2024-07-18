/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:46:35 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/17 16:40:46 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_ex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t len_s1 = ft_strlen(s1);
	size_t len_s2 = ft_strlen(s2);

	if (!s1)
		return ((char *)s1);
	if (!s2)
		return ((char *)s2);
	new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		new[i] = s2[i - len_s1];
		i++;
	}
	new[i] = '\0';
	return (new);
}
