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

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		sort3(stack_a);
	else if ((stack_size <= 5) && !is_sorted(*stack_a))
		sort5(stack_a, stack_b);
	else if (!is_sorted(*stack_a))
		radix(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_input(av);
	stack_a = fill_stack_values(ac, av);
	stack_b = NULL;
	//new_value(&stack_a);
	push_swap(&stack_a, &stack_b, stack_size(stack_a));
	free_stack(&stack_a);
}
