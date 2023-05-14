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

stack	*fill_stack_values(int ac, char **av)
{
	stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = 0;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error(&stack_a, 0);
		if (i == 1)
			stack_a = ft_lstnew(nb);
		else
			ft_lstadd_back(&stack_a, ft_lstnew((int)nb));
		i++;
	}
	return (stack_a);
}

stack	*ft_lstnew(int content)
{
	stack	*result;

	result = malloc(sizeof * result);
	if (!result)
		return (NULL);
	result->value = content;
	result->index = 0;
	result->next = NULL;
	return (result);
}

void	ft_lstadd_back(stack **lst, stack *new)
{
	stack	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

stack	*ft_lstlast(stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	stack_index(stack *stack)
{
	int i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = ++i;
		printf("index = %d value = %d\n", stack->index, stack->value);
		stack = stack->next;
	}
}