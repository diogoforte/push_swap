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

int	getmaxbits(stack *stack_a)
{
	int		maxbits;
	int		maxnum;
	stack	*temp;

	maxbits = 0;
	maxnum = 0;
	temp = stack_a;
	while (temp)
	{
		if (temp->value > maxnum)
			maxnum = temp->value;
		temp = temp->next;
	}
	while (maxnum)
	{
		maxbits++;
		maxnum >>= 1;
	}
	return (maxbits);
}

void	radix(stack **stack_a, stack **stack_b)
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
