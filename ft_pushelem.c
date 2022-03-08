/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushelem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:50:31 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/07 16:48:52 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// take the first element at the top of b and put it at the top of a. 
// Do nothing if b is empty.
void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_lst;

	if (!*stack_b)
		return ;
	else
	{
		temp_lst = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		temp_lst->next = *stack_a;
		*stack_a = temp_lst;
	}
	write (1, "pa\n", 3);
}

//  take the first element at the top of a and put it at the top of b.
//  Do nothing if a is empty.
void	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_lst;

	if (!*stack_a)
		return ;
	else
	{
		temp_lst = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		temp_lst->next = *stack_b;
		*stack_b = temp_lst;
	}
	write (1, "pb\n", 3);
}
