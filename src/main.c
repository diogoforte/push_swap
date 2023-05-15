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

int	main(int ac, char **av)
{
	stack	*stack_a;
	stack	*stack_b;
	int stacksize;

	if(!check_input(ac, av))
		return (0);
	stack_a = fill_stack_values(ac, av);
	stack_b = NULL;
	//stacksize = stack_index(stack_a);
	bubbleSort(stack_a);
	stacksize = stack_index(stack_a);
	stacksize -= 1;
	stack_b -= 1;
}

