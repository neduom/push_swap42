/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:41:04 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/10 11:15:03 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str, int i, int sign)
{
	long	res;

	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' || str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

static	int	check_max(char *str, int i, int sign)
{
	long	res;

	sign = 1;
	res = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != 32)
			return (1);
		res = res * 10 + (str[i] - '0');
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	initialize_stack(t_stack_node **stack_a, char **av, int i)
{
	int		count;
	long	nbr;
	char	**str;

	i = 0;
	while (av[++i])
	{
		str = ft_split(av[i], ' ');
		if (!str)
			return (ft_free_errors(stack_a), 1);
		count = -1;
		while (str[++count])
		{
			if (check_max(str[count], 0, 0))
				return (free_arr(str), ft_free_errors(stack_a), 1);
			nbr = ft_atol(str[count], 0, 0);
			if (check_duplicat(*stack_a, (int)nbr))
				return (free_arr(str), ft_free_errors(stack_a), 1);
			(ft_back(stack_a, ft_lstnew((int)nbr, 0)));
		}
		if (count == 0)
			return (free_arr(str), ft_free_errors(stack_a), 1);
		free_arr(str);
	}
	return (0);
}

void	assign_index(t_stack_node **stack_a)
{
	t_stack_node	*current;
	t_stack_node	*temp;
	int				index;

	current = *stack_a;
	index = 0;
	while (current)
	{
		temp = *stack_a;
		while (temp)
		{
			if (current->value > temp->value)
				index++;
			temp = temp->next;
		}
		current->index = index;
		index = 0;
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (parse(av) == 1)
		return (write(2, "Error\n", 6), 1);
	initialize_stack(&stack_a, av, 0);
	assign_index(&stack_a);
	if (is_stack_unsorted(&stack_a))
	{
		move_to_b(&stack_a, &stack_b, 0, 0);
		move_back_to_a(&stack_a, &stack_b, 0);
	}
	free_stack(&stack_a);
}
