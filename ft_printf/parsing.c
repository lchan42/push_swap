/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:21 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 15:32:19 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

char	*parsing_bonus_digit(char *str, t_struct *t_specifier)
{
	int		result;
	char	flag;

	result = 0;
	flag = *str;
	while (ft_isdigit(*(++str)))
		result = result * 10 + (*str - '0') % 10;
	if (flag == '.')
		t_specifier->precision = result;
	else
		t_specifier->width = result;
	return (str - 1);
}

void	parsing_bonus_flag_overwrites(int *flag_value, char specifier)
{
	if (*flag_value & SPACE && *flag_value & PLUS_SIGN)
		*flag_value -= SPACE;
	if (*flag_value & ZERO && *flag_value & LEFT_ADJUSTMENT)
		*flag_value -= ZERO;
	if ((*flag_value & ALTERNATE_FORME)
		&& (specifier != 'x') && (specifier != 'X'))
		*flag_value -= ALTERNATE_FORME;
	if (*flag_value & PLUS_SIGN && specifier == 'p')
		*flag_value -= PLUS_SIGN;
	if ((*flag_value & PRECISION)
		&& (specifier == 'c' || specifier == 'p'))
		*flag_value -= PRECISION;
	if (*flag_value & PRECISION && *flag_value & ZERO
		&& ft_strchr_booleen("diouxX", specifier))
		*flag_value -= ZERO;
}

void	parsing_bonus_flag_value(char flag, int *flag_value)
{
	if (flag == '#')
		*flag_value |= ALTERNATE_FORME;
	else if (flag == ' ')
		*flag_value |= SPACE;
	else if (flag == '+')
		*flag_value |= PLUS_SIGN;
	else if (flag == '-')
		*flag_value |= LEFT_ADJUSTMENT;
	else if (flag == '0')
		*flag_value |= ZERO;
	else if (flag == '.')
		*flag_value |= PRECISION;
}

void	parsing_bonus(char *str, t_struct *t_specifier)
{
	while (*(++str) != t_specifier->specifier)
	{
		if (ft_strchr(FLAGS, *str))
			parsing_bonus_flag_value(*str, &t_specifier->flag_value);
		if (*str == '.' && ft_isdigit(*(str + 1)))
			str = parsing_bonus_digit(str, t_specifier);
		else if (ft_isnonull_digit(*str))
			str = parsing_bonus_digit(str - 1, t_specifier);
	}
	parsing_bonus_flag_overwrites(&t_specifier->flag_value,
		t_specifier->specifier);
}

int	parsing(char *str, t_list **strchain, va_list arg_list)
{
	int			len;
	t_struct	t_specifier;

	len = 0;
	struct_init(&t_specifier);
	while (str[++len])
	{
		if (ft_strchr(SPECIFIERS, str[len]))
		{
			t_specifier.specifier = str[len];
			if (len > 1)
				parsing_bonus(str, &t_specifier);
			break ;
		}
	}
	specifier_tree(t_specifier.specifier, arg_list, &t_specifier);
	ft_add_specifier_content(strchain, &t_specifier);
	return (0);
}
