/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:44:45 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/11 10:31:42 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, false);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	free_stack(stack_a);
	return ;
}

void	move_to_b(t_stack_node **stack_a, t_stack_node **stack_b, int x, int i)
{
	t_stack_node	*tmp;

	if (ft_lstsize(*stack_a) <= 5)
		handle_five(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 100)
		x = 16;
	else
		x = 36;
	while (*stack_a)
	{
		tmp = *stack_a;
		if (tmp->index <= i)
		{
			pb(stack_b, stack_a);
			i++;
		}
		else if (tmp->index <= i + x)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	move_back_to_a(t_stack_node **stack_a, t_stack_node **stack_b,
		int stack_size)
{
	int	position_of_max;

	stack_size = ft_lstsize(*stack_b);
	while (stack_size)
	{
		assign_position(*stack_b);
		position_of_max = get_max_position(*stack_b);
		if (position_of_max < stack_size / 2)
		{
			while ((*stack_b)->position != position_of_max)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->position != position_of_max)
				rrb(stack_b, false);
		}
		pa(stack_a, stack_b);
		stack_size--;
	}
}
