/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 07:40:24 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/16 07:40:24 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(stack **stack)
{
	struct s_stack	*tmp;
	struct s_stack	*tail;
	struct s_stack	*before_tail;

	tail = ft_lstlast(*stack);
	before_tail = ft_lstbeforelast(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	rra(stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 3);
}

void	rrb(stack **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 3);
}

void	rrr(stack **stack_a, stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
