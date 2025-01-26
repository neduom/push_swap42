/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:25:32 by mel-moud          #+#    #+#             */
/*   Updated: 2025/01/25 10:35:49 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack_node **stack_a)
{
    t_stack_node    *largest_node;

    largest_node = find_max(*stack_a);
    if (*stack_a = largest_node)
        ra(stack_a);
    else if ((*stack_a)->next == largest_node)
        rra(stack_a, false);       
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a, false);
}
void    sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node    *smallest_node;

    smallest_node = find_min(*stack_a);
    if (is_stack_unsorted(stack_a))
    {
        while (true)
        {
            if (smallest_node->value != (*stack_a)->value)
                rra(stack_a, false);
            else
                break;
        }
        pb(stack_b, stack_a);
        sort_three(stack_a);
        pa(stack_a, stack_b);
        return ;
    }
}
void    sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node    *min_node;
    
    if (is_stack_unsorted(stack_a))
    {
        min_node = find_min(*stack_a);
        while (true)
        {
            if ((*stack_a)->next == min_node)
                ra(stack_a);
            else if (min_node->value != (*stack_a)->value)
                rra(stack_a, false);
            else
                break;
        }
        pb(stack_b, stack_a);
        sort_four(stack_a, stack_b);
        pa(stack_a, stack_b);
        return ;
    }
}