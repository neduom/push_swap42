/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:53:29 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/11 13:14:46 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
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
		if ((str[i] < '0' || str[i] > '9'))
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

void	ft_free(void *arr)
{
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while (arr[i])
		{
			ft_free((void *)arr[i]);
			i++;
		}
		ft_free((void *)arr);
	}
}
