/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:11:46 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 15:55:36 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew_with_count(void *content, int count)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	if (!tmp->content)
		count = 1;
	tmp->result = count;
	tmp->next = NULL;
	return (tmp);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
			ft_lstlast(*alst)->next = new;
	}
}

int	ft_print_list_result(t_list *alst)
{
	int	result;

	result = 0;
	while (alst)
	{
		if (!alst->content)
			write(1, "\0", 1);
		else
			write(1, alst->content, alst->result);
		result = result + alst->result;
		alst = alst->next;
	}
	return (result);
}

void	free_list(t_list *alst)
{
	t_list	*tmp;

	tmp = alst;
	while (tmp)
	{
		free(tmp->content);
		tmp = tmp->next;
		free(alst);
		alst = tmp;
	}
}
