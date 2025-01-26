/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:04:53 by mel-moud          #+#    #+#             */
/*   Updated: 2025/01/24 14:26:41 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_stack_node **stack_a, bool display)
{
    t_stack_node *last_node;
    t_stack_node *second_last_node;

    if (ft_lstsize(*stack_a) < 2)
        return ;

    last_node = *stack_a;
    second_last_node = *stack_a;

    while (second_last_node->next->next)
        second_last_node = second_last_node->next;

    last_node = second_last_node->next;
    second_last_node->next = NULL;
    last_node->next = *stack_a;
    *stack_a = last_node;

    if (!display)
        write (1, "rra\n", 4);
}
void    rrb(t_stack_node **stack_b, bool display)
{
    t_stack_node *last_node;
    t_stack_node *second_last_node;

    if (ft_lstsize(*stack_b) < 2)
        return ;
    
    last_node = *stack_b;
    second_last_node = *stack_b;

    while (second_last_node->next->next)
        second_last_node = second_last_node->next;

    last_node = second_last_node->next;
    second_last_node->next = NULL;
    last_node->next = *stack_b;
    *stack_b = last_node;
    
    if (!display)
        write (1, "rrb\n", 4);
}
void    rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
    rra(stack_a, true);
    rrb(stack_b, true);
    write (1, "rrr\n", 4);
}
