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

void	push_swap(stack **stack_a, stack **stack_b, int stack_size)
{
	if (stack_size == 2 && is_sorted(*stack_a))
		sa(stack_a);
	//else if (stack_size == 3)
	//	tiny_sort(stack_a);
	//else if (stack_size > 3 && !is_sorted(*stack_a))
	//	sort(stack_a, stack_b);
	stack_b -= 1;
}

int	main(int ac, char **av)
{
	stack	*stack_a;
	stack	*stack_b;

	if(!check_input(ac, av))
		return (0);
	stack_a = fill_stack_values(ac, av);
	stack_b = NULL;
	printstack(stack_a);
	assign_index(stack_a, stack_size(stack_a) + 1);
	push_swap(&stack_a, &stack_b, stack_size(stack_a));
	printstack(stack_a);
}

void	printstack(stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}
