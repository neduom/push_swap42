/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:14:35 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/03 16:55:34 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_duplicat(t_stack_node *stack, int number)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*curr;
	t_stack_node	*next_node;

	curr = *stack;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
	*stack = NULL;
}

void	ft_free_errors(t_stack_node **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
