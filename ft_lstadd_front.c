/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:30:59 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/03 19:26:52 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_list	*ft_lstnew(int data)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->data = data;
	list->next = 0;
	return (list);
}

void	ft_sorts_a(t_list **stack_a, t_list **stack_b, t_utils *utils)
{
	int	index;
	int	min;
	int	moves;

	while (ft_listsize(*stack_a) > 3)
	{
		min = ft_findmin(stack_a);
		index = ft_indexingm(*stack_a, min);
		if (index < ft_listsize(*stack_a) / 2)
		{
			moves = index;
			while (moves-- > 0)
				ft_rotate_a(stack_a);
		}
		else
		{
			moves = ft_listsize(*stack_a) - index;
			while (moves-- > 0)
				ft_revrotate_a(stack_a);
		}
		ft_push_b(stack_a, stack_b);
	}
	if (!ft_isordered(*stack_a))
		ft_threenumb(stack_a);
	ft_sorts(&(*utils).stack_a, &(*utils).stack_b);
}
