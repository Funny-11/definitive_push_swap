/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:36:44 by gifanell          #+#    #+#             */
/*   Updated: 2025/06/25 22:22:11 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_node *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_node **a)
{
	int	max;

	if (is_sorted(*a))
		return ;

	max = find_max(*a);
	if ((*a)->value == max)
	{
		rotate_a(a);
	}
	else if ((*a)->next->value == max)
	{
		reverse_rotate_a(a);
	}
	if ((*a)->value > (*a)->next->value)
	{
		swap_a(a);
	}
}