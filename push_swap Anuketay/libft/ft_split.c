/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:20:00 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 19:29:29 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*temp;

	temp = s;
	tab_p = tab;
	while (*temp)
	{
		while (*s == sep)
			++s;
		temp = s;
		while (*temp && *temp != sep)
			++temp;
		if (*temp == sep || temp > s)
		{
			*tab_p = ft_substr(s, 0, temp - s);
			s = temp;
			++tab_p;
		}
	}
	*tab_p = NULL;
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}
/*
int	main(void)
{
	char	input[] = "This is a test string for splitting";
	char	separator;
	char	**result;
	int		i;

	separator = ' ';
	result = ft_split(input, separator);
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		free(result[i]); // Free memory allocated for each word
		i++;
	}
	free(result); // Free the array of strings
	return (0);
}
*/
