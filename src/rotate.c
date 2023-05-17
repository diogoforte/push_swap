/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:43:17 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/15 20:43:17 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(stack **stack)
{
	struct s_stack	*tmp;
	struct s_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = ft_lstlast(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(stack **stack_a, stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
