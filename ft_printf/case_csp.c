/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_csp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:25:54 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 15:27:38 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_case_c(int argument, char **t_specifier_content)
{
	char	c;

	if (!argument)
		*t_specifier_content = NULL;
	else
	{
		c = (char) argument;
		*t_specifier_content = ft_strndup(&c, 1);
	}
}

void	ft_case_s(char *argument, t_struct *t_specifier)
{
	int	len;

	if (argument)
		len = ft_strlen(argument);
	else
		len = ft_strlen("(null)");
	if (t_specifier->flag_value & PRECISION
		&& t_specifier->precision < len)
		len = t_specifier->precision;
	if (!argument)
		t_specifier->content = ft_strndup("(null)", len);
	else
		t_specifier->content = ft_strndup(argument, len);
}

int	ft_convertbase_size(unsigned long long int argument, int base)
{
	int	len;

	len = 0;
	while (argument)
	{
		argument /= base;
		len ++;
	}
	return (len);
}

char	*ft_printf_itoa_hexa(int len,
	unsigned long long int argument, char specifier)
{
	char	*content;
	int		added_bytes;

	added_bytes = 0;
	if (!argument)
		len++;
	if (specifier == 'p')
		added_bytes = 2;
	content = (char *) malloc((len + added_bytes + 1) * sizeof(char));
	if (!content)
		return (NULL);
	content[len + added_bytes] = '\0';
	while (--len + added_bytes >= added_bytes)
	{
		content[len + added_bytes] = HEXABASE[argument % 16];
		argument /= 16;
	}
	if (specifier == 'p')
	{
		content[1] = 'x';
		content[0] = '0';
	}
	return (content);
}

void	ft_case_p(unsigned long long int argument, char **t_specifier_content)
{
	int	len;

	len = ft_convertbase_size(argument, 16);
	*t_specifier_content = ft_printf_itoa_hexa(len, argument, 'p');
}
