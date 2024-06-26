/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:07:14 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/03 18:04:48 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_splitwithmed(t_utils *a, int median)
{
	int	num_of_iteration;
	int	i;

	i = 0;
	num_of_iteration = ft_listsize(a->stack_a) / 2;
	while (ft_listsize(a->stack_a) > 2)
	{
		if (i == num_of_iteration)
		{
			a->me = ft_list_to_array(a->stack_a);
			ft_arraysort(a->me, ft_listsize(a->stack_a));
			median = ft_findmedian(a->me, ft_listsize(a->stack_a));
			if (a->me)
				free(a->me);
			num_of_iteration = ft_listsize(a->stack_a) / 2;
			i = 0;
		}
		if ((a->stack_a)->data < median)
		{
			ft_push_b(&(a->stack_a), &(a->stack_b));
			i++;
		}
		else
			ft_rotate_a(&(a->stack_a));
	}
}

void	ft_splitwithchunk(t_utils *a)
{
	while (ft_listsize(a->stack_a) > 0)
	{
		a->me = ft_list_to_array(a->stack_a);
		ft_arraysort(a->me, ft_listsize(a->stack_a));
		a->count_top = ft_scantop(a->stack_a, a->me [20]);
		a->count_bot = ft_listsize(a->stack_a) - ft_sca(a->stack_a, a->me [20]);
		if (a->me)
			free(a->me);
		if (a->count_top < a->count_bot)
		{
			while (a->count_top-- > 0)
				ft_rotate_a(&(a->stack_a));
			ft_sorts_b(&(a->stack_b));
			ft_push_b(&(a->stack_a), &(a->stack_b));
		}
		else
		{
			while (a->count_bot-- > 0)
				ft_revrotate_a(&(a->stack_a));
			ft_sorts_b(&(a->stack_b));
			ft_push_b(&(a->stack_a), &(a->stack_b));
		}
	}
}

void	ft_threenumb(t_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
		ft_swap_a(*stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data)
		ft_rotate_a(stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
	{
		ft_swap_a(*stack_a);
		ft_revrotate_a(stack_a);
	}
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
	{
		ft_swap_a(*stack_a);
		ft_rotate_a(stack_a);
	}
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
		ft_revrotate_a(stack_a);
}

void	ft_sorts(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	max;
	int	moves;

	while (*stack_b)
	{
		max = ft_findmax(stack_b, ft_listsize(*stack_b));
		index = ft_indexing(*stack_b, max);
		if ((*stack_b)->data == max)
			ft_push_a(stack_a, stack_b);
		else if (index < ft_listsize(*stack_b) / 2)
		{
			moves = index;
			while (moves-- > 0)
				ft_rotate_b(stack_b);
		}
		else
		{
			moves = ft_listsize(*stack_b) - index;
			while (moves-- > 0)
				ft_revrotate_b(stack_b);
		}
	}
}

void	ft_sorts_b(t_list **stack_b)
{
	int	index;
	int	max;
	int	moves;

	while (*stack_b)
	{
		max = ft_findmax(stack_b, ft_listsize(*stack_b));
		index = ft_indexing(*stack_b, max);
		if ((*stack_b)->data == max)
			return ;
		else if (index < ft_listsize(*stack_b) / 2)
		{
			moves = index;
			while (moves-- > 0)
				ft_rotate_b(stack_b);
		}
		else
		{
			moves = ft_listsize(*stack_b) - index;
			while (moves-- > 0)
				ft_revrotate_b(stack_b);
		}
	}
}
// void	ft_sorts_a( t_list **stack_b)
// {
// 	int	index;
// 	int	min;
// 	int	moves;

// 	while (*stack_b)
// 	{
// 		min = ft_findmin(stack_b);
// 		index = ft_indexing(*stack_b, min);
// 		if ((*stack_b)->data == min)
// 			return ;
// 		else if (index < ft_listsize(*stack_b) / 2)
// 		{
// 			moves = index;
// 			while (moves-- > 0)
// 				ft_rotate_b(stack_b);
// 		}
// 		else
// 		{
// 			moves = ft_listsize(*stack_b) - index;
// 			while (moves-- > 0)
// 				ft_revrotate_b(stack_b);
// 		}
// 	}
// }
