/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:57:24 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/03 18:54:13 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_list;

typedef struct s_utils
{
	int		i;
	int		j;
	int		data;
	int		median;
	int		max;
	int		min;
	int		*array;
	int		*me;
	int		count_top;
	int		count_bot;
	int		count;
	char	**a;
	t_list	*stack_a;
	t_list	*stack_b;
}			t_utils;

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_checkdouble(t_utils *utils);
int		ft_checkdigit(long result, char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		*ft_list_to_array(t_list *stack_a);
int		ft_listsize(t_list *stack_a);
int		ft_findmedian(int *array, int size);
int		ft_findmax(t_list **stack_b, int size);
int		ft_findmin(t_list **stack_a);
void	ft_checkargs(t_utils *utils);
int		ft_indexing(t_list *list, int min);
int		ft_sca(t_list *list, int median);
int		ft_scantop(t_list *list, int median);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_clearleak(t_utils *utils, int a);
void	ft_swap_a(t_list *stack_a);
void	ft_swap_b(t_list *stack_b);
void	ft_swap_ab(t_list *stack_a, t_list *stack_b);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a(t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
void	ft_rotate_ab(t_list	**stack_a, t_list **stack_b);
void	ft_revrotate_a(t_list **stack_a);
void	ft_revrotate_b(t_list **stack_b);
void	ft_revrotate_ab(t_list **stack_a, t_list **stack_b);
void	ft_arraysort(int *array, int len);
void	ft_sorts(t_list **stack_a, t_list **stack_b);
void	ft_splitwithmed(t_utils *a, int median);
void	ft_threenumb(t_list **stack_a);
void	ft_twonumb(t_list **stack_a);
void	ft_firstcheck(t_list **stack_a, t_list **stack_b);
void	ft_sorts_b(t_list **stack_b);
void	ft_splitwithchunk(t_utils *a);
void	ft_clearmatrix(char **str);
void	ft_free_and_null(int **content);
int		ft_isordered(t_list *stack_a);
int		ft_disordered(t_list *stack_a);
void	ft_sorts_a(t_list **stack_a, t_list **stack_b, t_utils *utils);
int		ft_indexingm(t_list *list, int min);

#endif
