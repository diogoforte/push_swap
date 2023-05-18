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

#include <stdio.h>
#include <stdlib.h>

int getMaxBits(stack* stack_a)
{
    int maxBits = 0;
    int maxNum = 0;
    stack* temp = stack_a;
    while (temp)
    {
        if (temp->value > maxNum)
            maxNum = temp->value;
        temp = temp->next;
    }
    while (maxNum)
    {
        maxBits++;
        maxNum >>= 1;
    }
    return maxBits;
}

void radix(stack** stack_a, stack** stack_b)
{
    int maxBits = getMaxBits(*stack_a);
	int bit = 0;
    while (bit < maxBits)
    {
        int counter = 0;
        int size = stack_size(*stack_a);
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
