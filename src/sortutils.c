/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:18:04 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/19 10:18:04 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_negatives_to_top(t_stack **stack_a)
{
	t_stack		*temp;
	int			rotations;
	int			min_negative;

	temp = *stack_a;
	rotations = 0;
	min_negative = 0;
	while (temp)
	{
		if (temp->value < 0 && temp->value < min_negative)
		{
			min_negative = temp->value;
			break ;
		}
		rotations++;
		temp = temp->next;
	}
	while (rotations--)
		ra(stack_a);
}

int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_rsorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	last_value(t_stack *stack)
{
	int		value;

	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->next == 0)
			value = stack->value;
		stack = stack->next;
	}
	return (value);
}
