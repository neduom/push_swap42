/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:30 by mel-moud          #+#    #+#             */
/*   Updated: 2025/01/24 13:43:28 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack_node **stack_a)
{
    t_stack_node *first_node;
    t_stack_node *last_node;

    if (ft_lstsize(*stack_a) < 2)
        return;

    first_node = *stack_a;
    last_node = *stack_a;

    while (last_node->next)
        last_node = last_node->next;
    
    *stack_a = first_node->next;
    first_node->next = NULL;
    last_node->next = first_node;
    
    write (1, "ra\n", 3);
}
void    rb(t_stack_node **stack_b)
{
    t_stack_node *first_node;
    t_stack_node *last_node;

    if (ft_lstsize(*stack_b) < 2)
        return ;
    
    first_node = *stack_b;
    last_node = *stack_b;
    
    while (last_node->next)
        last_node = last_node->next;

    *stack_b = first_node->next;
    first_node->next = NULL;
    last_node->next = first_node;

    write (1, "ra\n", 3);
}

void    rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write (1, "rr\n", 3);
}