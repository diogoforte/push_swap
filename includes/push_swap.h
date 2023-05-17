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
	int				index;
	struct s_stack	*next;
}	stack;

int check_input(int ac, char **av);
int check_num(char *av);
int check_duplicates(int ac, char **av);
int	ft_atoi(char *str);
void	ft_lstclear(stack **stack);
stack	*fill_stack_values(int ac, char **av);
stack	*ft_lstnew(int content);
void	ft_lstadd_back(stack **lst, stack *new);
stack	*ft_lstlast(stack *lst);
stack	*ft_lstbeforelast(stack *lst);
void	free_stack(stack **stack);
void	error(stack **stack_a, stack **stack_b);
int	stack_size(stack *stack);
void	assign_index(stack *stack_a, int stack_size);
int is_sorted(stack *stack);

void	push(stack **src, stack **dest);
void	pa(stack **stack_a, stack **stack_b);
void	pb(stack **stack_a, stack **stack_b);
void	rev_rotate(stack **stack);
void	rra(stack **stack_a);
void	rrb(stack **stack_b);
void	rrr(stack **stack_a, stack **stack_b);
void	rotate(stack **stack);
void	ra(stack **stack_a);
void	rb(stack **stack_b);
void	rr(stack **stack_a, stack **stack_b);
void	swap(stack *stack);
void	sa(stack **stack_a);
void	sb(stack **stack_b);
void	ss(stack **stack_a, stack **stack_b);

void	printstack(stack *stack);
#endif