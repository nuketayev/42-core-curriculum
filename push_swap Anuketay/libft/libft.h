/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:42:44 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 19:42:45 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
long	ft_atol(const char *s);
char	**ft_split(char const *str, char c);
void	ft_putendl_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
