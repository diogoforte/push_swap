/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 08:10:34 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/16 08:10:34 by dinunes-         ###   ########.fr       */
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

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	maxbits;
	int	bit;
	int	counter;
	int	size;

	maxbits = getmaxbits(*stack_a);
	bit = 0;
	while (bit < maxbits)
	{
		counter = 0;
		size = stack_size(*stack_a);
		while (counter < size)
		{
			if (((*stack_a)->value >> bit) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			counter++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
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
