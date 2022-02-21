/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/02/21 17:55:35 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	checkarg_isnumber(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i][j])
	{
		while (av[i][j])
			if (av[i][j] > '9' || av[i][j++] < '0')
		j = 0;
		i++;
	}
}

int	**tab_init (int ac, char **av)
{

	if (ac == 1)
	{
		
	}

	else if (ac > 1)

	else
		return (NULL);

}

int	check_duplicate()
{

}

int main (int ac, char **av)
{
	int	**tab;

	ac -= 1;
	tab = tab_init(ac, av);
}
