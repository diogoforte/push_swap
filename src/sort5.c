/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:17:53 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/22 23:22:59 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		if (is_sorted(*stack_a) && !*stack_b)
			return ;
		if ((*stack_a)->value == lowest_value(*stack_a))
			pb(stack_a, stack_b);
		else if (lowest_pos(*stack_a) < 2)
			ra(stack_a);
		else if (lowest_pos(*stack_a) >= 2)
			rra(stack_a);
	}
	sort3(stack_a);
	insertb(stack_a, stack_b);
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
