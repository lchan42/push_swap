/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_entrycheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/03/13 21:03:27 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ascii(char **av)
{
	int	i;
	int	j;

	if (!av[1])
		return (0);
	i = -1;
	j = 0;
	while (av[++i])
	{
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (strchr_booleen(av[i][j], "-+"))
				j++;
			if (!av[i][j] || av[i][j] > '9' || av[i][j] < '0')
				return (0);
			while (ft_isdigit(av[i][j]))
				j++;
			while (av[i][j] == ' ')
				j++;
		}
		j = 0;
	}
	return (1);
}
/*********************************************
 * this functions allows only one sign before numbers
 * return 0 if :
 * 		there's only sign and no digit
 * 		non_digit ascii is encountered
 * *******************************************/

char	*find_next_nbr(char *current_position, int *line, char **av)
{
	char	*tmp;

	if (!current_position && *line == 0)
		return (*(av + *line));
	tmp = current_position;
	while (tmp && *tmp == ' ')
		tmp++;
	while (tmp && (ft_isdigit(*tmp) || strchr_booleen(*tmp, "-+")))
		tmp++;
	while (tmp && *tmp == ' ')
		tmp++;
	if (tmp && *tmp)
		return (tmp);
	else
	{
		*line += 1;
		return (*(av + *line));
	}
}
/********************************************
 * purpose: get the next number in the char *str or the char **str
 * *******************************************/

int	check_overflow(int ac, char **av)
{
	int			i;
	char		*tmp;
	int			count;
	long int	number;

	i = 0;
	count = 0;
	tmp = NULL;
	while (i < ac)
	{
		tmp = find_next_nbr(tmp, &i, av);
		if (!tmp)
			break ;
		count = 0;
		if (strchr_booleen(*(tmp + count), "-+"))
			count++;
		while (ft_isdigit(*(tmp + count)))
			count++;
		if (count > 11)
			return (0);
		number = ft_atol(tmp);
		if (number > 2147483647 || number < -2147483648)
			return (0);
	}
	return (1);
}
/*******************************************
 * 11 represent max len of an integer
 * *******************************************/	

int	check_duplicate(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	i = 0;
	j = 0;
	tmp = NULL;
	while (i < ac)
	{
		tmp = find_next_nbr(tmp, &i, av);
		j = i;
		tmp2 = find_next_nbr(tmp, &j, av);
		while (tmp && tmp2 && *tmp2)
		{
			if (ft_atoi(tmp2) == ft_atoi(tmp))
			{
				printf("tmp2 = %d, tmp = %d\n", ft_atoi(tmp2), ft_atoi(tmp));
				return (0);
			}
			tmp2 = find_next_nbr(tmp2, &j, av);
		}
	}
	return (1);
}
/*********************************************
 * case duplicate only works after check ascii and check_overflow.
 * *******************************************/

int	entry_check(int ac, char **av)
{
//	del_print_tab(av);
/*	if (ac < 3 || !check_ascii(av)
		|| !check_overflow(ac, av) || !check_duplicate(ac, av))
		return (0);*/
	if (!check_ascii(av))
	{
		printf("check_ascii\n");
		return (0);
	}
	if (!check_overflow(ac, av))
	{
		printf("check_over_flow\n");
		return (0);
	}
	if (!check_duplicate(ac, av))
	{
		printf("duplicate\n");
		return (0);
	}
	return (1);
}
