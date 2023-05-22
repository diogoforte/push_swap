/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 07:31:51 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/12 07:31:51 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = 0;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = check_duplicates(stack_a, ft_atoi(av[i]));
		if (nb > 2147483647 || nb < -2147483648)
			errorhandling(&stack_a, 0);
		if (i == 1)
			stack_a = ft_lstnew(nb);
		else
			ft_lstadd_back(&stack_a, ft_lstnew((int)nb));
		i++;
	}
	return (stack_a);
}

long int	ft_atoi(char *str)
{
	long int	res;
	int			sign;

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
	res *= sign;
	return (res);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
