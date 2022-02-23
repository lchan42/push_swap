/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/02/23 17:12:54 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    del_print_tab(char **tab)
{
        int     i;

        i = -1;
        while (tab[++i])
                printf("%s\n", tab[i]);
}

int	strchr_booleen(char c, char *str)
{
	while(*str)
		if (c == *(str++))
			return (1);
	return (0);
}

int	check_ascii(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = -1;
	while (av[i])
	{
		while (av[i][++j])
		{
			while (strchr_booleen(av[i][j], " -+"))
				j++;
			if (!av[i][j] || av[i][j] > '9' || av[i][j] < '0')
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}
/*********************************************
 * this functions allows signs and space before numbers
 * Will then  return 0 if :
 * 		there's only sign
 * 		non_digit ascii is encountered
 * */	
/*
int	check_overflow(char **av)
{
	int			i;
	char		*tmp;
	long int	number;

	i = -1;
	while (av[++i])
	{
		tmp = av[i];
		while (strchr_booleen(*tmp, "-+"))
			tmp++;
		if (ft_strlen(tmp) > 11)
			return (0);
		number = ft_atol(tmp);
   		if (number > 2147483647 || number < -2147483648)
			return (0);
	}
	return (1);
}*/
/*******************************************
 * This function is here to prevent overflows
 * 		11 represent max len of an integer
 * 		*/

int	check_duplicate(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	while (++i < ac - 1)
	{
		k = i + 1;
		while (av[k++][j])
			while (av[i][++j] && av[k][j] && av[i][j] == av[k][j])
				if (!av[i][j + 1] && !av[k][j + 1])
					return (0);
	}
	return (1);
}

int	entry_check(int ac, char **av)
{
	printf("working on : \n");
	del_print_tab(av);
	/*
	if (ac < 3
	|| !check_ascii(av) || !check_overflow(av) || !check_duplicate(ac, av))
		return 0;
	*/
	if (!check_ascii(av))
	{
		printf("check_ascii found an issue\n");
		return (0);
	}
//	else if (!check_overflow(av))
//	{
//		printf("check_overflow found an issue\n");
//		return (0);
//		}
	else if (!check_duplicate(ac, av))
	{
		printf("check_duplicate found an issue\n");
		return (0);
	}
	return (1);
}

int main (int ac, char **av)
{
	if (!entry_check(ac - 1, (++av)))
	{
		printf("error");
		return (0);
	}
	else
		printf("entry is ok");
		
}

/**********************************************
 * ac - 1 coz we do not care about the first entry.
 */




/* TO DO LIST
 * check school corrector;
 * garbage colector;
 * */
