/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:15:13 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/02/07 18:26:41 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_revrotate_a(t_list **stack_a)
{
	t_list	*last2;
	t_list	*last;

	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last2 = NULL;
	last = *stack_a;
	while (last->next != NULL)
	{
		last2 = last;
		last = last->next;
	}
	last2->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write (1, "rra\n", 4);
}

void	ft_revrotate_b(t_list **stack_b)
{
	t_list	*last2;
	t_list	*last;

	if (stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last2 = NULL;
	last = *stack_b;
	while (last->next != NULL)
	{
		last2 = last;
		last = last->next;
	}
	last2->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write (1, "rrb\n", 4);
}

void	ft_revrotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_revrotate_a(stack_a);
	ft_revrotate_b(stack_b);
	write (1, "rrr\n", 4);
}
