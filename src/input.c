/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:43:28 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/18 00:43:28 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **av)
{
	av++;
	while (*av)
	{
		if (!check_num(*av))
			errorhandling(0, 0);
		av++;
	}
	return (1);
}

int	check_num(char *av)
{
	if (*av == 45 || *av == 43)
		av++;
	while (*av)
	{
		if (*av < 48 || *av > 57)
			return (0);
		av++;
	}
	return (1);
}

int	check_duplicates(t_stack *lst, int num)
{
	t_stack	*temp;

	if (!lst)
		return (num);
	temp = lst;
	while (temp)
	{
		if (num == temp->value)
			errorhandling(&lst, 0);
		temp = temp->next;
	}
	return (num);
}

void	free_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	errorhandling(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}
