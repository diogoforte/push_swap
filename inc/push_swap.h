/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 06:31:04 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/12 06:31:04 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				is_negative;
	struct s_stack	*next;
}	t_stack;

int				check_input(int ac, char **av);
int				check_num(char *av);
int				check_duplicates(int ac, char **av);
long int		ft_atoi(char *str);
void			ft_lstclear(t_stack **t_stack);
t_stack			*fill_stack_values(int ac, char **av);
t_stack			*ft_lstnew(int content);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack			*ft_lstlast(t_stack *lst);
t_stack			*ft_lstbeforelast(t_stack *lst);
void			free_stack(t_stack **t_stack);
void			errorhandling(t_stack **stack_a, t_stack **stack_b);
int				stack_size(t_stack *t_stack);
void			assign_index(t_stack *stack_a, int stack_size);
int				is_sorted(t_stack *t_stack);
void			push(t_stack **src, t_stack **dest);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);
void			rev_rotate(t_stack **t_stack);
void			rra(t_stack **stack_a);
void			rrb(t_stack **stack_b);
void			rrr(t_stack **stack_a, t_stack **stack_b);
void			rotate(t_stack **t_stack);
void			ra(t_stack **stack_a);
void			rb(t_stack **stack_b);
void			rr(t_stack **stack_a, t_stack **stack_b);
void			swap(t_stack *t_stack);
void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);
void			ss(t_stack **stack_a, t_stack **stack_b);
void			radix(t_stack **stack_a, t_stack **stack_b);
int				getmaxbits(t_stack *stack_a);
void			push_negatives_to_top(t_stack **stack_a);
void			push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
int				absolute(int n);
#endif