/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:15:46 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/03 18:24:35 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_findmax(t_list **stack_b, int size)
{
	int	max;
	int	*array;

	max = 0;
	array = ft_list_to_array(*stack_b);
	ft_arraysort(array, ft_listsize(*stack_b));
	max = array[size - 1];
	if (array)
		free(array);
	return (max);
}

int	ft_findmin(t_list **stack_a)
{
	int	min;
	int	*array;

	array = ft_list_to_array(*stack_a);
	ft_arraysort(array, ft_listsize(*stack_a));
	min = array[0];
	if (array)
		free(array);
	return (min);
}

int	ft_indexing(t_list *list, int max)
{
	int	i;

	i = 0;
	while (list->next != NULL)
	{
		if (list->data == max)
			return (i);
		i++;
		list = list->next;
	}
	return (i);
}

int	ft_indexingm(t_list *list, int min)
{
	int	i;

	i = 0;
	while (list->next != NULL)
	{
		if (list->data == min)
			return (i);
		i++;
		list = list->next;
	}
	return (i);
}

int	ft_scantop(t_list *list, int median)
{
	int	i;

	i = 0;
	while (list->next != NULL)
	{
		if (list->data < median)
			return (i);
		i++;
		list = list->next;
	}
	return (i);
}

int	ft_sca(t_list *list, int median)
{
	int	i;
	int	temp;

	i = 0;
	while (list->next != NULL)
	{
		if (list->data < median)
			temp = i;
		i++;
		list = list->next;
	}
	return (temp);
}
