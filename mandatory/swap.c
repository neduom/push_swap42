/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:02:04 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/03 16:32:18 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a, bool display)
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
	if (!display)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **stack_b, bool display)
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
	if (!display)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a, true);
	sb(stack_b, true);
	write(1, "ss\n", 3);
}
