/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:36:52 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/19 19:36:52 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 5)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	else
		pb(stack_a, stack_b);
	sort3(stack_a);
	insertb(stack_a, stack_b);
}

void	sort3(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value == highest_value(*stack))
		ra(stack);
	else if ((*stack)->next->value == highest_value(*stack))
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

int	highest_value(t_stack *stack)
{
	int		value;

	if (stack == NULL)
		return (0);
	value = stack->value;
	while (stack)
	{
		if (stack->value > value)
			value = stack->value;
		stack = stack->next;
	}
	return (value);
}

int	lowest_value(t_stack *stack)
{
	int		value;

	if (stack == NULL)
		return (0);
	value = stack->value;
	while (stack)
	{
		if (stack->value < value)
			value = stack->value;
		stack = stack->next;
	}
	return (value);
}

void	insertb(t_stack **stack_a, t_stack **stack_b)
{
	int		moved;

	while (*stack_b)
	{
		moved = 0;
		if ((*stack_a)->value < (*stack_b)->value
			&& (*stack_b)->value > last_value(*stack_a))
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
		{
			while ((*stack_a)->value < (*stack_b)->value
				&& moved < stack_size(*stack_a))
			{
				ra(stack_a);
				moved++;
			}
			pa(stack_a, stack_b);
		}
		while (moved--)
			rra(stack_a);
	}
}
