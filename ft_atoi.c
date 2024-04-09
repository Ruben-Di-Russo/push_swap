/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:34:51 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/03 19:05:45 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10;
		result = result + (*str - 48);
		str++;
	}
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return (result * sign);
}

int	ft_disordered(t_list *stack_a)
{
	t_list	*list;
	int		value;

	list = stack_a;
	value = list->data;
	while (list)
	{
		if (value < list->data)
			return (0);
		value = list->data;
		list = list->next;
	}
	return (1);
}
