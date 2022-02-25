/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_content_to_chained_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:24:22 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 16:13:25 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_add_str_content(char *str, t_list **strchain)
{
	int		count;
	t_list	*new_chain;

	count = 0;
	while (str[count] && str[count] != '%')
		count++;
	new_chain = ft_lstnew_with_count(ft_strndup(str, count), count);
	ft_lstadd_back(strchain, new_chain);
}

void	ft_add_specifier_content(t_list **strchain, t_struct *t_specifier)
{
	int		content_len;
	t_list	*new_chain;

	content_len = 0;
	if (!t_specifier->content && t_specifier->specifier != 'c')
		return ;
	if (t_specifier->flag_value & PRECISION)
		ft_add_precision(t_specifier);
	if (t_specifier->width)
		ft_add_padding(t_specifier);
	while (t_specifier->content && t_specifier->content[content_len])
		content_len++;
	if (t_specifier->specifier == 'c' && t_specifier->width > 0)
		new_chain = ft_lstnew_with_count(t_specifier->content,
				t_specifier->width);
	else
		new_chain = ft_lstnew_with_count(t_specifier->content, content_len);
	ft_lstadd_back(strchain, new_chain);
}
