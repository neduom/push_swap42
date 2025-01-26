/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:52 by mel-moud          #+#    #+#             */
/*   Updated: 2025/01/24 12:56:11 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *first_node;
    t_stack_node *second_node;

    if (*stack_b == NULL)
        return ;
    
    first_node = *stack_a;
    second_node = *stack_b;

    *stack_b = second_node->next;
    second_node->next = first_node;
    *stack_a = second_node;

    write (1, "pa\n", 3);
}
void    pb(t_stack_node **stack_b, t_stack_node **stack_a)
{
    t_stack_node *first_node;
    t_stack_node *second_node;

    if  (*stack_a == NULL)
        return ;
        
    first_node = *stack_a;
    second_node = *stack_b;

    *stack_a = first_node->next;
    first_node->next = second_node;
    *stack_b = first_node;

    write (1, "pb\n",3);
}
