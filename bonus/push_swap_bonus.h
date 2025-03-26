/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:37 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/11 13:02:33 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					position;
	struct s_stack_node	*next;
}						t_stack_node;

int						ft_lstsize(t_stack_node *lst);
int						is_stack_unsorted(t_stack_node **list);
int						get_max_position(t_stack_node *stack);
int						check_duplicat(t_stack_node *stack, int number);

char					**ft_split(char const *s, char c);

t_stack_node			*ft_lstnew(int value, int index);
t_stack_node			*ft_lstlast(t_stack_node *lst);
t_stack_node			*find_max(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);

void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);
void					ra(t_stack_node **stack_a);
void					rb(t_stack_node **stack_b);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b);
void					pa(t_stack_node **stack_a, t_stack_node **stack_b);
void					pb(t_stack_node **stack_b, t_stack_node **stack_a);
void					rra(t_stack_node **stack_a);
void					rrb(t_stack_node **stack_b);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b);

void					move_back_to_a(t_stack_node **stack_a,
							t_stack_node **stack_b, int stack_size);
void					move_to_b(t_stack_node **stack_a,
							t_stack_node **stack_b, int x, int i);
int						initialize_stack(t_stack_node **stack_a, char **av,
							int i);
void					ft_back(t_stack_node **lst, t_stack_node *new);
void					assign_position(t_stack_node *stack);
void					free_stack(t_stack_node **stack);
void					ft_free_errors(t_stack_node **stack);

void					ft_free(void *arr);
void					free_arr(char **arr);

#endif