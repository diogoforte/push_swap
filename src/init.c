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

stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = 0;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, 0);
		if (i == 1)
			stack_a = ft_lstnew((int)nb);
		else
			ft_lstadd_back(&stack_a, ft_lstnew((int)nb));
		i++;
	}
	return (stack_a);
}

stack	*ft_lstnew(void *content)
{
	stack	*result;

	result = malloc(sizeof(stack));
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