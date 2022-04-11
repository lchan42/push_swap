/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:59:14 by lchan             #+#    #+#             */
/*   Updated: 2022/04/11 19:51:58 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strchr_booleen(char c, char *str)
{
	while (*str)
		if (c == *(str++))
			return (1);
	return (0);
}

int	ps_count_digit(char *tmp, int count)
{
	while (*(tmp + count) == '0')
		tmp++;
	while (ft_isdigit(*(tmp + count)))
		count++;
	return (count);
}
/***************************************
 * useful in the funtion check_duplicate
 * *************************************/

int	ps_count_firstarg_nbr(char *tmp)
{
	int		count;
	char	next;

	count = 1;
	while (tmp && *tmp)
	{
		next = *(tmp + 1);
		if (*tmp == ' ' && next && next != ' ')
			count++;
		tmp++;
	}
	return (count);	
}
/**************************************
 * used in the function entry_check
 * count the number of element separated by space in av[1]
 * ************************************/

int	ft_ps_is_even_nbr(int n)
{
	if (n == 0 || n == -1 || n == 1)
		return (0);
	if (n % 2 == 0 || n == 2)
		return (1);
	return (0);
}

int	ps_ab_val(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}
