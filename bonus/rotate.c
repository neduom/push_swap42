/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:30 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/03 16:57:20 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack_node **stack_a)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	first_node = *stack_a;
	last_node = *stack_a;
	while (last_node->next)
		last_node = last_node->next;
	*stack_a = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	rb(t_stack_node **stack_b)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	first_node = *stack_b;
	last_node = *stack_b;
	while (last_node->next)
		last_node = last_node->next;
	*stack_b = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
