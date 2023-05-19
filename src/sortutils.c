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

int	getmaxbits(t_stack *stack_a)
{
	int		maxbits;
	int		maxnum;
	int		maxbitshold;
	t_stack	*temp;

	maxbitshold = 0;
	temp = stack_a;
	while (temp)
	{
		maxnum = absolute(temp->value);
		maxbits = 0;
		while (maxnum)
		{
			maxbits++;
			maxnum >>= 1;
		}
		if (temp->value < 0)
			maxbits++;
		if (maxbitshold < maxbits)
			maxbitshold = maxbits;
		temp = temp->next;
	}
	return (maxbitshold);
}

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
