/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 06:30:59 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/12 06:30:59 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);

	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size > 2 && !is_sorted(*stack_a))
	{
		radix(stack_a, stack_b);
		if (!is_sorted(*stack_a))
			push_negatives_to_top(stack_a);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_input(ac, av);
	stack_a = fill_stack_values(ac, av);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b, stack_size(stack_a));
	free_stack(&stack_a);
}
