/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:36:52 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/19 19:36:52 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value == highest_value(*stack))
		ra(stack);
	else if ((*stack)->next->value == highest_value(*stack))
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
