/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:59:14 by lchan             #+#    #+#             */
/*   Updated: 2022/04/12 17:00:17 by lchan            ###   ########.fr       */
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
/**********************************************
 * used in entrycheck and in buildstack
 * go from one number to another.
 * ********************************************/

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
