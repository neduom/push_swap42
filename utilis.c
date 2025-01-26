/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:26:06 by mel-moud          #+#    #+#             */
/*   Updated: 2025/01/24 15:12:36 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lstnew(int value, int index)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}
t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*max;
	
	current = stack;
	max = current;
	while(current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}
t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node *current;
	t_stack_node *min;
	
	current = stack;
	min = current;
	while(current)
	{
		if (current->value < current->value)
			min	= current;
		current = current->next;
	}
	return (min);
}
int	is_stack_unsorted(t_stack_node **list)
{
	t_stack_node *curr;

	curr = (*list);
	while(curr)
	{
		if (curr->next != NULL)
		{
			if (curr->value > curr->next->value)
				return (1);
		}
		curr = curr->next;
	}
	return (0);
}