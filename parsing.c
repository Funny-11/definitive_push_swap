/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:38:13 by gifanell          #+#    #+#             */
/*   Updated: 2025/06/25 22:34:40 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_exit(t_node **stack)
{
    ft_putendl_fd("Error", 2);
    free_stack(stack);
    exit(1);
}

int	is_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
//long (per controllare overflow prima di fare il cast a int)
bool    is_integer(const char *str)
{
    long    n;

    if (!str || *str == '\0')
        return (false);
    if (*str == '-' || *str == '+')
        str++;
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (false);
        str++;
    }
    n = ft_atoi(str);
    if (n < INT_MIN || n > INT_MAX)
        return (false);
    return (true);
}

void    parse_args(t_node **stack, char **argv)
{
    int     i;
    int     value;

    i = 0;
    while (argv[i])
    {
        if (!is_integer(argv[i]))
            error_exit(stack);
        value = ft_atoi(argv[i]);
        if (is_duplicate(*stack, value))
            error_exit(stack);
        if(!append_node(stack, stack_new(value)))
            error_exit(stack);
        i++;
    }
}
