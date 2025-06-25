/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:37:04 by gifanell          #+#    #+#             */
/*   Updated: 2025/06/25 22:41:08 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_next_bigger(t_node *stack, int value)
{
	t_node	*result;
	t_node	*temp;
	
	temp = stack;
	result = NULL;
	while (temp != NULL)
	{
		if (temp->value > value)
		{
			if (result == NULL || result->value > temp->value)
				result = temp;
		}
		temp = temp->next;	
	}
	if (result == NULL)
		return(find_min(stack));
	return (result);
}

int	find_posix(t_node *stack, int value)
{
	int	posix = 0;

	while (stack)
	{
		if(value == stack->value)
			return(posix);
		posix++;
		stack = stack->next;
	}
	return (-1);
}

void	calculate_cost(t_node *stack_a, t_node *stack_b)
{
	t_node	*temp;
	int	posix;
	int	stack_size_a;
	int	stack_size_b;

	temp = stack_b;
	posix = 0;
	stack_size_a = stack_size(stack_a);
	stack_size_b = stack_size(stack_b);

	while (temp)
	{
		int	target_posix;
		t_node	*target;
		
		target = find_next_bigger(stack_a, temp->value);
		target_posix = find_posix(stack_a, target->value);
		temp->total_cost = 0;
		if (posix <= stack_size_b / 2)
		{
			temp->total_cost = posix;
			temp->rot_b = posix;
			temp->rev_rot_b = INT_MAX;
		}
		else
		{
			temp->total_cost = stack_size_b - posix;
			temp->rev_rot_b = stack_size_b - posix;
			temp->rot_b = INT_MAX;
		}
		if (target_posix <= stack_size_a / 2)
		{
			temp->total_cost += target_posix;
			temp->rot_a = target_posix;
			temp->rev_rot_a = INT_MAX;
		}
		else
		{
			temp->total_cost += stack_size_a - target_posix;
			temp->rev_rot_a = stack_size_a - target_posix;
			temp->rot_a = INT_MAX;
		}
		temp = temp->next;
		posix++;
	}
}

t_node	*get_lowest_cost(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->total_cost < min->total_cost)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	execute_best_node(t_node **stack_a, t_node **stack_b)
{
	t_node *best_node = get_lowest_cost(*stack_b);

	if (best_node == NULL)
		return;
	if (best_node->rot_a < best_node->rev_rot_a && best_node->rot_b < best_node->rev_rot_b)
	{
		while (best_node->rot_a != 0 && best_node->rot_b != 0)
		{
			rotate_both(stack_a, stack_b);
			best_node->rot_a--;
			best_node->rot_b--;
		}
	}
	else if (best_node->rot_a > best_node->rev_rot_a && best_node->rot_b > best_node->rev_rot_b)
	{
		while (best_node->rev_rot_a != 0 && best_node->rev_rot_b != 0)
		{
			reverse_rotate_both(stack_a, stack_b);
			best_node->rev_rot_a--;
			best_node->rev_rot_b--;
		}
	}
	if (best_node->rot_b < best_node->rev_rot_b)
	{
		while (best_node->rot_b != 0)
		{
			rotate_b(stack_b);
			best_node->rot_b--;
		}
	}
	else
	{
		while (best_node->rev_rot_b != 0)
		{
			reverse_rotate_b(stack_b);
			best_node->rev_rot_b--;
		}
	}
	if (best_node->rot_a < best_node->rev_rot_a)
	{
		while (best_node->rot_a != 0)
		{
			rotate_a(stack_a);
			best_node->rot_a--;
		}
	}
	else
	{
		while (best_node->rev_rot_a != 0)
		{
			reverse_rotate_a(stack_a);
			best_node->rev_rot_a--;
		}
	}
	push_a(stack_a, stack_b);
}
