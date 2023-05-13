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

void	ft_lstiter(stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	stack	*stack_a;
	stack	*stack_b;
	if(!check_input(av))
		return (0);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	ft_lstiter(stack_a);
	ft_lstiter(stack_b);
}