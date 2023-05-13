/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 06:31:04 by dinunes-          #+#    #+#             */
/*   Updated: 2023/05/12 06:31:04 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct stack	*next;
}	stack;

int check_input(char **av);
int check_num(char *av);
int	ft_atoi(char *str);
void	ft_lstclear(stack **stack);
stack	*fill_stack_values(int ac, char **av);
stack	*ft_lstnew(void *content);
void	ft_lstadd_back(stack **lst, stack *new);
stack	*ft_lstlast(stack *lst);
void	ft_lstiter(stack *lst);


#endif