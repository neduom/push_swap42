/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:54:33 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/11 13:22:54 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	execute_command(char *command, t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	if (!ft_strcmp(command, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(command, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(command, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(command, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(command, "pb\n"))
		pb(stack_b, stack_a);
	else if (!ft_strcmp(command, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(command, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(command, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(command, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	checker(t_stack_node **stack_a, t_stack_node **stack_b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		if (!execute_command(cmd, stack_a, stack_b))
		{
			free(cmd);
			free_stack(stack_a);
			free_stack(stack_b);
			ft_free_errors(stack_a);
		}
		free(cmd);
	}
	if (is_stack_unsorted(stack_a) || *stack_b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!av[1][0] || av[1][0] == 32)
		return (write(2, "Error\n", 6), 1);
	initialize_stack(&stack_a, av, 0);
	checker(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
