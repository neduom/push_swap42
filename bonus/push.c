/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:52 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/03 16:56:55 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*first_node;

	if (*stack_b == NULL)
		return ;
	first_node = *stack_b;
	*stack_b = first_node->next;
	first_node->next = *stack_a;
	*stack_a = first_node;
}

void	pb(t_stack_node **stack_b, t_stack_node **stack_a)
{
	t_stack_node	*first_node;

	if (*stack_a == NULL)
		return ;
	first_node = *stack_a;
	*stack_a = first_node->next;
	first_node->next = *stack_b;
	*stack_b = first_node;
}
