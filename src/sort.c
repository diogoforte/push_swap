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

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	maxbits;
	int	bit;

	maxbits = getmaxbits(*stack_a);
	bit = 0;
	while (bit < maxbits)
	{
		process_stack_a(stack_a, stack_b, bit);
		bit++;
		process_stack_b(stack_a, stack_b, bit);
	}
}

void	process_stack_a(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	counter;
	int	size;

	counter = 0;
	size = stack_size(*stack_a);
	while (counter < size && *stack_a)
	{
		if (((*stack_a)->value >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		counter++;
	}
}

void	process_stack_b(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	counter;
	int	size;

	counter = 0;
	size = stack_size(*stack_b);
	while (counter < size && *stack_b)
	{
		if (((*stack_b)->value >> bit) & 1)
			pa(stack_a, stack_b);
		else if (!is_sorted(*stack_a))
			rb(stack_b);
		else
			while (*stack_b)
				pa(stack_a, stack_b);
		counter++;
	}
}

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
		maxnum = temp->value;
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
