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

int	lowest_pos(t_stack *stack)
{
	int	value;

	if (stack == NULL)
		return (0);
	while (stack && stack->value != lowest_value(stack))
	{
		value++;
		stack = stack->next;
	}
	return (value);
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
	while (stack)
	{
		if (stack->value < value)
			value = stack->value;
		stack = stack->next;
	}
	return (value);
}
