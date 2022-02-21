/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sign_to_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:13:01 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 15:13:46 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_add_space_or_plus(char **t_specifier_content, int flag_value)
{
	if (flag_value & PLUS_SIGN)
		*t_specifier_content = printf_strjoin_frees2("+", *t_specifier_content);
	else if (flag_value & SPACE)
		*t_specifier_content = printf_strjoin_frees2(" ", *t_specifier_content);
}
