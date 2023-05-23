/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wins.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:19:00 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/23 02:35:02 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_wins(t_stack	*lst, int compare)
{
	t_stack	*temp;
	int		counter;

	temp = lst;
	counter = 1;
	while (temp)
	{
		if (temp->value < compare)
			counter++;
		temp = temp->next;
	}
	return (counter);
}

void	new_value(t_stack	**lst)
{
	t_stack	*temp;
	t_stack	*new;

	new = NULL;
	temp = *lst;
	while (temp)
	{
		ft_lstadd_back(&new, ft_lstnew(count_wins(*lst, temp->value)));
		temp = temp->next;
	}
	free_stack(lst);
	*lst = new;
}
