/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_duxxmajpercent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:27:52 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 15:29:07 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_case_d(int argument, char **t_specifier_content, int flag_value)
{
	int			len;
	long int	nb;

	nb = argument;
	if (nb > 0)
		len = ft_convertbase_size(nb, 10);
	else
	{
		nb = -nb;
		len = ft_convertbase_size(nb, 10);
		len++;
	}
	*t_specifier_content = (char *) malloc((len + 1) * sizeof(char));
	if (!*t_specifier_content)
		return ;
	(*t_specifier_content)[len] = '\0';
	while (--len >= 0)
	{
		(*t_specifier_content)[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (argument < 0)
		(*t_specifier_content)[0] = '-';
	if (argument >= 0)
		ft_add_space_or_plus(t_specifier_content, flag_value);
}

void	ft_case_u(unsigned int argument, char **t_specifier_content)
{
	int	len;

	len = ft_convertbase_size(argument, 10);
	if (!argument)
		len = 1;
	*t_specifier_content = (char *) malloc((len + 1) * sizeof(char));
	if (!*t_specifier_content)
		return ;
	(*t_specifier_content)[len] = '\0';
	while (--len >= 0)
	{
		(*t_specifier_content)[len] = argument % 10 + '0';
		argument /= 10;
	}
}

void	ft_case_x(unsigned int argument, t_struct *t_specifier)
{
	int	len;

	len = ft_convertbase_size(argument, 16);
	if (argument && (t_specifier->flag_value & ALTERNATE_FORME))
		t_specifier->content = ft_printf_itoa_hexa(len, argument, 'p');
	else
		t_specifier->content = ft_printf_itoa_hexa(len, argument, 'x');
}

void	ft_case_xmaj(unsigned argument, t_struct *t_specifier)
{
	int	len;
	int	i;

	i = 0;
	len = ft_convertbase_size(argument, 16);
	if (argument && (t_specifier->flag_value & ALTERNATE_FORME))
		t_specifier->content = ft_printf_itoa_hexa(len, argument, 'p');
	else
		t_specifier->content = ft_printf_itoa_hexa(len, argument, 'x');
	while ((t_specifier->content)[i])
	{
		if ((t_specifier->content)[i] >= 97 && (t_specifier->content)[i] <= 122)
			(t_specifier->content)[i] -= 32;
		i++;
	}
}

void	ft_case_percent(char **t_specifier_content)
{	
	*t_specifier_content = ft_strdup("%");
}
