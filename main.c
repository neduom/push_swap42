/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:41:04 by mel-moud          #+#    #+#             */
/*   Updated: 2025/01/26 16:33:10 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  long    ft_atol(char *str, int i, int sign)
{
    long    res;

    res = 0;
    sign = 1;
    while (str[i] == ' ')
        i++;
    if (str[i] == '-'  || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i])
        (write(2, "Error\n", 6), exit(1));
    while(str[i])
    {
        res = res * 10 + (str[i] - '0');
        if ((res * sign) > INT_MAX || (res * sign) < INT_MIN || (str[i] < '0' || str[i] > '9'))
            (write(2, "Error\n", 6), exit(1));
        i++;
    }
    if (str[i])
        (write(2, "Error\n", 6), exit(1));
    return (res * sign);
}