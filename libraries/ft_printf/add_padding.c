/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:14:01 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 19:20:05 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_add_padding_onright_cnull(t_struct *t_specifier,
		char **padded_content)
{
	int		i;
	char	padding;

	i = 0;
	if (t_specifier->flag_value & ZERO)
		padding = '0';
	else
		padding = ' ';
	(*padded_content)[i] = '\0';
	while (i < t_specifier->width)
		(*padded_content)[++i] = padding;
}

void	ft_add_padding_onright(t_struct *t_specifier)
{
	char	*padded_content;
	int		i;
	char	padding;

	padded_content = (char *)malloc(t_specifier->width + 1);
	if (!padded_content)
		return ;
	if (!t_specifier->content && t_specifier->specifier == 'c')
		ft_add_padding_onright_cnull(t_specifier, &padded_content);
	else
	{
		i = -1;
		if (t_specifier->flag_value & ZERO)
			padding = '0';
		else
			padding = ' ';
		while (t_specifier->content[++i])
			padded_content[i] = t_specifier->content[i];
		while (i < t_specifier->width)
			padded_content[i++] = padding;
		padded_content[t_specifier->width] = '\0';
	}
	free(t_specifier->content);
	t_specifier->content = padded_content;
}

void	ft_add_padding_onleft_bis(int content_len, t_struct *t_specifier,
		char **padded_content, int *i)
{
	int		j;
	char	padding;

	j = 0;
	if (t_specifier->flag_value & ZERO)
		padding = '0';
	else
		padding = ' ';
	while (*i < t_specifier->width && j < content_len)
	{
		if (ft_strchr_booleen("dixX", t_specifier->specifier)
			&& ft_strchr_booleen("-+ xX", t_specifier->content[j])
			&& padding == '0')
		{
			if (ft_strchr_booleen("dixX", t_specifier->specifier)
				&& ft_strchr_booleen("xX", t_specifier->content[j]))
				(*padded_content)[1] = t_specifier->content[j++];
			else
				(*padded_content)[0] = t_specifier->content[j++];
			(*padded_content)[(*i)++] = padding;
		}
		else
			(*padded_content)[(*i)++] = t_specifier->content[j++];
	}
}

void	ft_add_padding_onleft(int content_len, t_struct *t_specifier)
{
	int		i;
	int		j;
	char	padding;
	char	*padded_content;

	i = -1;
	j = 0;
	if (t_specifier->flag_value & ZERO)
		padding = '0';
	else
		padding = ' ';
	padded_content = (char *)malloc(t_specifier->width + 1);
	if (!padded_content)
		return ;
	while (++i < t_specifier->width - content_len)
		padded_content[i] = padding;
	if (t_specifier->specifier == 'c' && !t_specifier->content)
		while (i < t_specifier->width - 1 && j < content_len)
			padded_content[i++] = t_specifier->content[j++];
	else
		ft_add_padding_onleft_bis(content_len,
			t_specifier, &padded_content, &i);
	padded_content[i] = '\0';
	free(t_specifier->content);
	t_specifier->content = padded_content;
}

void	ft_add_padding(t_struct *t_specifier)
{
	int		content_len;

	if (t_specifier->content)
		content_len = ft_strlen(t_specifier->content);
	else
		content_len = 1;
	if (t_specifier->width <= content_len)
		return ;
	if (t_specifier->flag_value & LEFT_ADJUSTMENT)
		ft_add_padding_onright(t_specifier);
	else
		ft_add_padding_onleft(content_len, t_specifier);
}
