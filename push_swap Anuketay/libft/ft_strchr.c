/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:31:07 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 19:31:07 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	symbol;
	char	*string;
	int		i;

	i = 0;
	string = (char *)s;
	symbol = c;
	while (string[i] != symbol)
	{
		if (string[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)string + i);
}
