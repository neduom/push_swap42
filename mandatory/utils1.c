/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:35:21 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/11 11:27:27 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digits(int c)
{
	return ((c >= '0' && c <= '9') || c == '+' || c == '-');
}

int	is_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_digits(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	parse(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0] || is_char(av[i]))
			return (1);
		i++;
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
