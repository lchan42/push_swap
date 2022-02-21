/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:10:45 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 15:11:21 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	struct_init(t_struct *t_specifier)
{
	t_specifier->specifier = 0;
	t_specifier->flag_value = 0;
	t_specifier->width = 0;
	t_specifier->precision = 0;
	t_specifier->content = NULL;
}

char	*printf_strjoin_frees2(char const *s1, char const *s2)
{
	char	*joined;
	size_t	index;
	int		i;

	index = 0;
	if (s1 && s2)
		joined = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !joined)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		joined[index] = s1[i];
		index++;
	}
	i = -1;
	while (s2[++i])
	{
		joined[index] = s2[i];
		index++;
	}
	joined[index] = '\0';
	free((void *)s2);
	return (joined);
}

char	*printf_strjoin_free(char const *s1, char const *s2)
{
	char	*joined;
	size_t	index;
	int		i;

	index = 0;
	if (s1 && s2)
		joined = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !joined)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		joined[index] = s1[i];
		index++;
	}
	i = -1;
	while (s2[++i])
	{
		joined[index] = s2[i];
		index++;
	}
	joined[index] = '\0';
	free((void *)s1);
	free((void *)s2);
	return (joined);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (*s1 != '\0')
	{
		*dup = *s1;
		s1++;
		dup++;
	}
	*dup = '\0';
	return (dup - len);
}

char	*ft_strndup(const char *s1, int len)
{
	char	*dup;

	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	dup[len] = '\0';
	while (len--)
		dup[len] = s1[len];
	return (dup);
}
