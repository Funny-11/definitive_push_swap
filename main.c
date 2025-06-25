/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:37:14 by gifanell          #+#    #+#             */
/*   Updated: 2025/06/25 22:47:10 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     find_median(t_node *stack)
{
    int     len_stack;
    int     i;
    t_node  *median;
    
    median = find_min(stack);
    len_stack = stack_size(stack);
    i = 0;
    while (i < len_stack / 2)
    {
        median = find_next_bigger(stack, median->value);
        i++;
    }
    if (!median)
        return(0);
    return(median->value);
}

void    rotate_min_to_top(t_node **stack_a)
{
    t_node  *min;
    int     min_posix;
    int     len_stack_a;

    if(!stack_a || !*stack_a)
        return ;
    min = find_min(*stack_a);
    min_posix = find_posix(*stack_a, min->value);
    len_stack_a = stack_size(*stack_a);
    if (min_posix <= len_stack_a / 2)
    {
        while (*stack_a != min)
			rotate_a(stack_a);
    }
    else
    {
        while (*stack_a != min)
			reverse_rotate_a(stack_a);
    }
}

void    solve(t_node **stack_a, t_node **stack_b)
{
    int         len_stack_a;
    int         len_stack_b;
    const int   median = find_median(*stack_a);
   
    len_stack_a = stack_size(*stack_a);
    while(len_stack_a > 3 && !is_sorted(*stack_a))
    {
        push_b(stack_a, stack_b);
        if ((*stack_b)->value > median)
            rotate_b(stack_b);
        len_stack_a--;
    }
    sort_three(stack_a);
    len_stack_b = stack_size(*stack_b);
    while (len_stack_b > 0)
    {
        calculate_cost(*stack_a, *stack_b);
        execute_best_node(stack_a, stack_b);
        len_stack_b--;
    }
    rotate_min_to_top(stack_a);
}

int main(int argc, char **argv)
{
    t_node	*stack_a;
    t_node	*stack_b;

    (void)argc;
    stack_a = NULL;
    stack_b = NULL;
    parse_args(&stack_a, argv + 1);
    solve(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}