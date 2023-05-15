/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 06:36:45 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/12 06:36:45 by dinunes-         ###   ########.fr       */
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
				return (0);
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
					return (0);
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

void	error(stack **stack_a, stack **stack_b)
{
	if (stack_a == 0 || *stack_a != 0)
		free_stack(stack_a);
	if (stack_b == 0 || *stack_b != 0)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_lstclear(stack **lst)
{
	stack *tmp;

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



int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res * sign);
}