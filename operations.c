/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:37:59 by gifanell          #+#    #+#             */
/*   Updated: 2025/06/25 22:28:53 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack, int should_print, char *str)
{
    t_node	*first;
    t_node	*second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    if(should_print)
    	ft_putstr_fd(str, 1);
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    
}

void	swap_b(t_node **stack)
{
	swap(stack, 1, "sb\n");
}

void	swap_a(t_node **stack)
{
	swap(stack, 1, "sa\n");
}

void    push(t_node **src, t_node **dest, int should_print, char *str)
{
    t_node	*temp;

    if (!src || !*src)
        return ;
    if(should_print)
    	ft_putstr_fd(str, 1);
    temp = *src;
    *src = temp->next;
    temp->next = *dest;
    *dest = temp;
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b, 1, "pb\n");
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a, 1, "pa\n");
}

void	rotate(t_node **stack, int should_print, char *str)
{
    t_node	*first;
    t_node	*last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    if(should_print)
    	ft_putstr_fd(str, 1);
    first = *stack;
    *stack = first->next;
    last = *stack;
    while (last && last->next)
        last = last->next;
    if (last)
        last->next = first;
    first->next = NULL;
}

void	rotate_b(t_node **stack)
{
	rotate(stack, 1, "rb\n");
}

void	rotate_a(t_node **stack)
{
	rotate(stack, 1, "ra\n");
}

void	reverse_rotate(t_node **stack, int should_print, char *str)
{
    t_node	*before_last;
    t_node	*last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    if(should_print)
    	ft_putstr_fd(str, 1);
    before_last = *stack;
    while (before_last->next && before_last->next->next)
        before_last = before_last->next;
    last = before_last->next;
    before_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void	reverse_rotate_b(t_node **stack)
{
	reverse_rotate(stack, 1, "rrb\n");
}

void	reverse_rotate_a(t_node **stack)
{
	reverse_rotate(stack, 1, "rra\n");
}

void    swap_both(t_node **stack_a, t_node **stack_b)
{
    swap(stack_a, 0, NULL);
    swap(stack_b, 0, NULL);
    write(1, "ss\n", 3);
}

void    rotate_both(t_node **stack_a, t_node **stack_b)
{
    rotate(stack_a, 0, NULL);
    rotate(stack_b, 0, NULL);
    write(1, "rr\n", 3);
}

void    reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
    reverse_rotate(stack_a, 0, NULL);
    reverse_rotate(stack_b, 0, NULL);
    write(1, "rrr\n", 4);
}

