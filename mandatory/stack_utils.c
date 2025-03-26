/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:56:37 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/05 18:19:33 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack_node *lst)
{
	int				i;
	t_stack_node	*r;

	i = 0;
	r = lst;
	if (!lst)
		return (0);
	while (r)
	{
		r = r->next;
		i++;
	}
	return (i);
}

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	assign_position(t_stack_node *stack)
{
	t_stack_node	*curr;
	int				i;

	i = 0;
	curr = stack;
	while (curr)
	{
		curr->position = i;
		i++;
		curr = curr->next;
	}
}

int	get_max_position(t_stack_node *stack)
{
	t_stack_node	*curr;
	t_stack_node	*max;

	curr = stack;
	max = curr;
	while (curr)
	{
		if (curr->value > max->value)
			max = curr;
		curr = curr->next;
	}
	return (max->position);
}
