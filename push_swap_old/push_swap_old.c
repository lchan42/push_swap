/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/02/23 15:10:46 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strchr_booleen(char c, char *str)
{
	while(*str)
		if (c == *(str++))
			return (1);
	return (0);
}

int	check_isnumber_or_space(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = -1;
	while (av[i])
	{
		while (av[i][++j])
			if (av[i][j] != ' ' && (av[i][j] > '9' || av[i][j] < '0'))
				return (0);
		j = 0;
		i++;
	}
	return (1);
}

void	del_print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%s\n", tab[i]);
}

void	del_print_tab_int(int *tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%d\n", tab[i]);
}

char	*from_av_to_str(int ac, char **av)
{
	int		i;
	int		j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	len = ac;
	while (av[++i])
		len += ft_strlen(av[i]);
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (++i <= ac)
	{
		while (av[i][j])
			*(str++) = av[i][j++];
		j = 0;
		if (i < ac)
			*(str++) = ' ';
	}
	*(str++) = '\0';
	return (str - len);
}
/**********************************************
 *this function's purpose is to turn multiple av into a single string
 *the returned str is then used by ft_split
 **********************************************/

int	*tab_int_init(char **tab_char)
{
	int	tab_len;
	int	i;
	int	*tab_int;

	tab_len = 0;
	i = -1;
	while (*(tab_char++))
		tab_len++;
	tab_int = (int *)malloc(tab_len * sizeof(int));
	if (!tab_int)
		return (0);
	tab_char -= tab_len + 1;
	while (++i < tab_len)
		tab_int[i] = ft_atol(tab_char[i]);
	return (tab_int);
}

char	**tab_char_init(int ac, char **av)
{
	char	**tab_char;
	int		*tab_int;

	tab_char = NULL;
	tab_int = 0;
	if (ac == 0 || !check_isnumber_or_space(av))
	{
		printf("entry error");
		return (NULL);
	}
	else if (ac == 1)
		tab_char = ft_split(av[1], ' ');
	else if (ac > 1)
		tab_char = ft_split(from_av_to_str(ac, av), ' ');
	if (tab_char)
		tab_int = tab_int_init(tab_char);
	if (tab_int)
		del_print_tab_int(tab_int);
		//del_print_tab(tab_char);
	return (tab_char);
}


/**********************************************
 * check if entry is correct
 * parse into tab via either split or 
*/
/*
int	check_duplicate()
{

}
*/
int main (int ac, char **av)
{
	char	**tab_char;

	tab_char = tab_char_init(ac - 1, av);
}

/**********************************************
 * ac - 1 coz we do not care about the first entry.
 */




/* TO DO LIST
 * check school corrector;
 * garbage colector;
 * */
