/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:59:14 by lchan             #+#    #+#             */
/*   Updated: 2022/03/31 12:47:57 by lchan            ###   ########.fr       */
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

int	ft_ps_is_even_nbr(int n)
{
	if (n == 0 || n == -1 || n == 1)
		return (0);
	if (n % 2 == 0 || n == 2)
		return (1);
	return (0);
}
