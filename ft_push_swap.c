/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:33:11 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/03 19:08:25 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_printlst(t_list *head)
{
	t_list	*current_node;

	current_node = head;
	while (current_node != NULL)
	{
		printf("%d\n", current_node->data);
		current_node = current_node->next;
	}
}

void	ft_firstcheck(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_a(*stack_a);
	ft_push_a(stack_a, stack_b);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_a(*stack_a);
	if ((*stack_a)->data < (*stack_b)->data)
	{
		ft_push_b(stack_a, stack_b);
		ft_swap_b(*stack_b);
		ft_push_a(stack_a, stack_b);
	}
}

int	ft_fill_the_stack(int argc, char **argv, t_utils *utils)
{
	utils->i = 1;
	utils->stack_b = NULL;
	utils->stack_a = NULL;
	while (utils->i < argc)
	{
		utils->a = ft_split(argv[utils->i], ' ');
		utils->j = 0;
		if (!utils->a)
			return (0);
		while (utils->a[utils->j])
		{
			utils->data = ft_atoi(utils->a[utils->j]);
			if (!ft_checkdigit(utils->data, utils->a[utils->j]))
				return (0);
			ft_lstadd_back(&utils->stack_a, ft_lstnew(utils->data));
			utils->j++;
		}
		ft_clearmatrix(utils->a);
		utils->i++;
	}
	return (1);
}

void	ft_clearleak(t_utils *utils, int a)
{
	t_list	*temp;

	while (utils->stack_a)
	{
		temp = utils->stack_a->next;
		free(utils->stack_a);
		utils->stack_a = temp;
	}
	if (utils->array && a)
		free(utils->array);
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	if (argc < 2)
		return (0);
	if (!ft_fill_the_stack(argc, argv, &utils))
	{
		write (1, "Error\n", 6);
		ft_clearleak(&utils, 0);
		return (0);
	}
	if (!ft_checkdouble(&utils))
	{
		write (1, "Error\n", 6);
		ft_clearleak(&utils, 1);
		return (0);
	}
	if (ft_isordered(utils.stack_a))
	{
		ft_clearleak(&utils, 1);
		return (0);
	}
	else
		ft_checkargs(&utils);
	ft_clearleak(&utils, 1);
}
