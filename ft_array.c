/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:44:50 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/02/14 17:00:52 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_listsize(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	*ft_list_to_array(t_list *stack_a)
{
	int		*array;
	int		i;
	int		list_size;
	t_list	*temp;

	i = 0;
	list_size = ft_listsize(stack_a);
	if (stack_a == NULL)
		return (NULL);
	array = malloc(sizeof(int) * list_size + 1);
	temp = stack_a;
	while (temp)
	{
		array[i] = temp->data;
		temp = temp->next;
		i++;
	}
	return (array);
}

int	ft_findmedian(int *array, int size)
{
	int	median;

	if (size % 2 == 0)
		median = array[(size) / 2];
	else
		median = (array[(size - 1) / 2]);
	return (median);
}

int	ft_findchunk(int *array)
{
	int	chunk;

		chunk = array[20];
	return (chunk);
}

void	ft_arraysort(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < len)
	{
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
		i++;
	}
}
