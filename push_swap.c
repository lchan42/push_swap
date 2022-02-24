/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/02/24 19:54:26 by lchan            ###   ########.fr       */
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

	i = -1;
	j = 0;
	while (av[++i])
	{
		while (av[i][j])
		{
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

char	*case_multi_number_str(char *current_position, int *line, char **av)
{
	char	*tmp;

	if (!current_position && *line == 0)
		return (*(av + *line));
	tmp = current_position;
	while (tmp && ft_isdigit(*tmp))
		tmp++;
	while (tmp && *tmp == ' ')
		tmp++;
	if (tmp && *tmp)
		return (tmp);
	else
	{
		*line = *line + 1;
		return (*(av + *line));
	}
}

int	check_overflow(int ac, char **av)
{
	int			i;
	char		*tmp;
	int			count;
	long int	number;

	i = 0;
	tmp = NULL;
	while (i < ac)
	{
		tmp = case_multi_number_str(tmp, &i, av);
		count = 0;
		while(*tmp == ' ')
			tmp++;
		if (ft_strchr(*(tmp + count), "-+"))
			count++;
		while (ft_isdigit(tmp + count))
			count++;
		if (count > 11)
			return (0);
		number = ft_atol(tmp);
   		if (number > 2147483647 || number < -2147483648)
			return (0);
	}
	return (1);
}

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
		tmp = case_multi_number_str(tmp, &i, av);
		j = i;
		tmp2 = case_multi_number_str(tmp, &j, av);
		while (tmp && tmp2 && *tmp2)
		{
			if (ft_atoi(tmp2) == ft_atoi(tmp))
				return (0);
			tmp2 = case_multi_number_str(tmp2, &j, av);
		}
	}
	return (1);
}
/**************************************************
 * case duplicate only works after check ascii.
 * */
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
	}/*
	else if (!check_overflow(av))
	{
		printf("check_overflow found an issue\n");
		return (0);
	}*/
	else if (!check_duplicate(ac, av)) //CHECK DUPLICATE DO NOT WORK WITH ANEGATIVE ENTRY
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
 * cd /Users/lchan/Downloads
 * echo -n "" | ./checker_Mac "- 1" 2 3 "7  +5 6" 8
 * echo "rra" | ./checker_Mac "2 3" "4 5 6 1"
 * */
