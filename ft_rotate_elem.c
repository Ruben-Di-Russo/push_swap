/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:58:09 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/02 20:01:34 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rotate_a(t_list **stack_a)
{
	t_list	*start;
	t_list	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	start = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = start->next;
	start->next = NULL;
	last->next = start;
	write (1, "ra\n", 3);
}

void	ft_rotate_b(t_list **stack_b)
{
	t_list	*start;
	t_list	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	start = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = start->next;
	start->next = NULL;
	last->next = start;
	write (1, "rb\n", 3);
}

//ra and rb at the same time.
void	ft_rotate_ab(t_list	**stack_a, t_list **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
	write (1, "rr\n", 3);
}

void	ft_free_and_null(int **content)
{
	if (*content)
	{
		free(*content);
		*content = NULL;
	}
}
