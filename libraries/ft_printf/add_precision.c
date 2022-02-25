/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:22:33 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 15:24:09 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_precision_case_null(t_struct *t_specifier)
{
	if (t_specifier->flag_value & ALTERNATE_FORME
		&& ft_strlen(t_specifier->content) == 1)
	{
		free(t_specifier->content);
		t_specifier->content = ft_strdup("");
	}
	else if (t_specifier->specifier != 's'
		&& !(t_specifier->flag_value & ALTERNATE_FORME)
		&& t_specifier->content[0] == '0')
	{
		free(t_specifier->content);
		t_specifier->content = ft_strdup("");
	}
	else if (t_specifier->specifier != 's'
		&& ft_strchr_booleen(" +", t_specifier->content[0])
		&& t_specifier->content[1] == '0')
	{
		t_specifier->content[1] = '\0';
	}
}

void	ft_precision_case_signed(t_struct *t_specifier, int content_len)
{
	char	*index;
	int		i;
	int		new_content_len;
	char	*new_content;

	index = t_specifier->content;
	i = 0;
	new_content_len = t_specifier->precision + 1;
	new_content = (char *)malloc((new_content_len + 1) * sizeof(char));
	if (!new_content)
		return ;
	new_content[0] = t_specifier->content[0];
	while (++i < new_content_len - content_len + 1)
		new_content[i] = '0';
	while (*(++index))
		new_content[i++] = *index;
	new_content[new_content_len] = '\0';
	free(t_specifier->content);
	t_specifier->content = new_content;
}

void	ft_precision_case_0x(t_struct *t_specifier, int content_len)
{
	char	*index;
	int		i;
	int		new_content_len;
	char	*new_content;

	index = t_specifier->content;
	i = 1;
	new_content_len = t_specifier->precision + 2;
	new_content = (char *)malloc((new_content_len + 1) * sizeof(char));
	if (!new_content)
		return ;
	new_content[0] = t_specifier->content[0];
	new_content[1] = t_specifier->content[1];
	while (++i < new_content_len - content_len + 2)
		new_content[i] = '0';
	index++;
	while (*(++index))
		new_content[i++] = *index;
	new_content[new_content_len] = '\0';
	free(t_specifier->content);
	t_specifier->content = new_content;
}

void	ft_precision_case_unsigned(t_struct*t_specifier, int content_len)
{	
	char	*add_content;

	content_len = t_specifier->precision - content_len;
	add_content = (char *)malloc((content_len + 1) * sizeof(char));
	if (!add_content)
		return ;
	add_content[content_len] = '\0';
	while (content_len--)
		add_content[content_len] = '0';
	t_specifier->content = printf_strjoin_free(add_content,
			t_specifier->content);
}

void	ft_add_precision(t_struct *t_specifier)
{
	int		content_len;

	if (t_specifier->precision == 0)
		ft_precision_case_null(t_specifier);
	content_len = ft_strlen(t_specifier->content);
	if ((t_specifier->specifier == 's'
			|| content_len > t_specifier->precision))
		return ;
	if (ft_strchr_booleen("-+ ", t_specifier->content[0]))
		ft_precision_case_signed(t_specifier, content_len);
	else if (t_specifier->content[0] == '0'
		&& (ft_strchr_booleen("xX", t_specifier->content[1])))
		ft_precision_case_0x(t_specifier, content_len);
	else
		ft_precision_case_unsigned(t_specifier, content_len);
}
