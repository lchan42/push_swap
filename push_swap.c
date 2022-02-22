/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/02/22 16:58:31 by lchan            ###   ########.fr       */
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
 **/

int	**tab_init(int ac, char **av)
{
	char	**tab_char;
	int		**tab_int

	tab = NULL;
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
		//del_print_tab(tab_char);
	return (return tab_int);
}

/**********************************************
 * check if entry is correct
 * parse into tab via either split or 
*/

int	check_duplicate()
{

}

int main (int ac, char **av)
{
	int	**tab;

	tab = tab_init(ac - 1, av);
}

/**********************************************
 * ac - 1 coz we do not care about the first entry.
 */




/* TO DO LIST
 * garbage colector;
