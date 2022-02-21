/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:29:20 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 15:29:51 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	specifier_tree(char specifier, va_list arg_list, t_struct *t_specifier)
{
	if (specifier == 'c')
		ft_case_c(va_arg(arg_list, int), &t_specifier->content);
	else if (specifier == 's')
		ft_case_s(va_arg(arg_list, char *), t_specifier);
	else if (specifier == 'p')
		ft_case_p((unsigned long long int)va_arg(arg_list, void *),
			&t_specifier->content);
	else if (specifier == 'd')
		ft_case_d(va_arg(arg_list, int), &t_specifier->content,
			t_specifier->flag_value);
	else if (specifier == 'i')
		ft_case_d(va_arg(arg_list, int), &t_specifier->content,
			t_specifier->flag_value);
	else if (specifier == 'u')
		ft_case_u(va_arg(arg_list, unsigned int), &t_specifier->content);
	else if (specifier == 'x')
		ft_case_x(va_arg(arg_list, unsigned int), t_specifier);
	else if (specifier == 'X')
		ft_case_xmaj(va_arg(arg_list, unsigned int), t_specifier);
	else if (specifier == '%')
		ft_case_percent(&t_specifier->content);
}
