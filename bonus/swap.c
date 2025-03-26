/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:02:04 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/03 16:58:03 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack_node **stack_a)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	first_node = *stack_a;
	second_node = (*stack_a)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack_a = second_node;
}

void	sb(t_stack_node **stack_b)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	first_node = *stack_b;
	second_node = (*stack_b)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack_b = second_node;
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
