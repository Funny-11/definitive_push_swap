/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:38:30 by gifanell          #+#    #+#             */
/*   Updated: 2025/06/25 21:31:22 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_new(int value) //nuovo nodo per la pila
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_node	*append_node(t_node **stack, t_node *new) //aggiunge un nodo alla fine della pila
{
	t_node	*temp;

	if (!new)
		return (NULL);
	if (!*stack)
	{
		*stack = new;
		return (new);
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return(*stack);
}

int		stack_size(t_node *stack) //conta il numero di nodi nella pila
{
	int	count = 0;

	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	free_stack(t_node **stack) //libera la memoria della pila
{
	t_node	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int		is_sorted(t_node *stack) //controlla se la pila è gia' ordinata
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

