/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing_entrycheck.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/04/12 18:26:41 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_count_element(int ac, char **av)
{
	int		i;
	char *	tmp;
	int		count;

	i = -1;
	count = 0;
	while (++i < ac)
	{
		tmp = av[i];
		while (tmp && *tmp)
		{
			while (tmp && *tmp && *tmp == ' ')
				tmp++;
			if (*tmp && *tmp != ' ')
				count++;
			while (*tmp && *tmp != ' ')
				tmp++;
		}
	}
	return (count);
}
/**************************************************
 * count nbr of element separated by a space in av.
 * ************************************************/

int	check_ascii(char **av)
{
	int	i;
	int	j;

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
			if (av[i][j] != ' ' && av[i][j] != '\0')
				return (0);
			while (av[i][j] == ' ')
				j++;
		}
		j = 0;
	}
	return (1);
}
/******************************************************
 * this functions allows only one sign before numbers
 * return 0 if :
 * 		there's only sign and no digit
 * 		non_digit ascii is encountered
 * ****************************************************/

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
		count = ps_count_digit(tmp, count);
		if (count > 11)
			return (0);
		number = ft_atol(tmp);
		if (number > 2147483647 || number < -2147483648)
			return (0);
	}
	return (1);
}
/************************************
 * 11 represent max len of an integer
 * **********************************/	

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
		printf("ac = %d\n", ac);
		tmp = find_next_nbr(tmp, &i, av);
		printf("tmp = %s\n", tmp);
		j = i;
		tmp2 = find_next_nbr(tmp, &j, av);
		printf("tmp2 = %s\n", tmp2);
		while (tmp && tmp2 && *tmp2)
		{
			if (*tmp && *tmp2 && ft_atoi(tmp2) == ft_atoi(tmp))
				return (0);
			tmp2 = find_next_nbr(tmp2, &j, av);
		}
	}
	return (1);
}
/*****************************************************************
 * case duplicate only works after check ascii and check_overflow.
 * ***************************************************************/

int	entry_check(int ac, char **av)
{
	if (ps_count_element(--ac, ++av) < 2)
	{
		//printf("error ARG_NBR_ERROR");
		ps_exit_error(ARG_NBR_ERROR);
	}
	else if (!check_ascii(av))
	{
	//	printf("error ascii\n");
		ps_exit_error(ASCII_ERROR);
	}
	else if (!check_overflow(ac, av))
	{
	//	printf("error check_overflow\n");
		ps_exit_error(OVERFLOW_ERROR);
	}
	else if (!check_duplicate(ac, av))
	{
	//	printf("error duplicate\n");
		ps_exit_error(DUPLICATE_ERROR);
	}
	printf("entry is ok\n");
	return (1);
}
