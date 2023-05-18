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

int check_input(int ac, char **av)
{
	if (check_duplicates(ac, av))
	{
		av++;
		while (*av)
		{
			if(!check_num(*av))
				errorhandling(0, 0);
			av++;
		}
	}
	else
		return 0;
	return (1);
}

int check_num(char *av)
{
	while (*av)
	{
		if (av[0] == 45)
			av++;
		if(*av < 48 || *av > 57)
			return (0);
		av++;
	}
	return (1);
}

int check_duplicates(int ac, char **av)
{
    int i;
    int j;
	int k;

	i = 1;
    while (i < ac)
	{
        j = i + 1;
        while (j < ac)
		{
            k = 0;
            while (av[i][k] == av[j][k])
			{
                if (av[i][k] == '\0')
					errorhandling(0, 0);
                k++;
            }
			j++;
        }
		i++;
    }
    return (1);
}

void	free_stack(stack **lst)
{
	stack	*tmp;

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

void	errorhandling(stack **stack_a, stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}