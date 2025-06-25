/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:36:26 by gifanell          #+#    #+#             */
/*   Updated: 2025/06/25 22:27:29 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft.h"

# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;	// valore del nodo
	int				total_cost;
	
	int				rev_rot_a;
	int				rev_rot_b;
	int				rot_a;
	int				rot_b;
	struct s_node	*next; // puntatore al nodo successivo
}	t_node;

// Prototipi delle funzioni
t_node	*stack_new(int value); // crea un nuovo nodo per la pila
t_node	*append_node(t_node **stack, t_node *new); // aggiunge un nodo alla fine della pila
int		stack_size(t_node *stack); // conta il numero di nodi nella pila
void	free_stack(t_node **stack); // libera la memoria della pila
int		is_sorted(t_node *stack); // controlla se la pila è gia' ordinata
int		is_duplicate(t_node *stack, int value); // verifica se un valore è già presente nella pila
void    error_exit(t_node **stack); // gestisce gli errori
bool	is_integer(const char *str); // verifica se una stringa rappresenta un intero
void	parse_args(t_node **stack, char **argv); // analizza gli argomenti e popola la pila

// Funzioni per operazioni/gestione della pila
void    push(t_node **src, t_node **dest, int should_print, char *str); // sposta il primo elemento da stack_a a stack_b
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack, int should_print, char *str); // ruota gli elementi della pila verso l'alto
void	rotate_a(t_node **stack);
void	rotate_b(t_node **stack);
void	reverse_rotate(t_node **stack, int should_print, char *str); // ruota gli elementi della pila verso il basso
void	reverse_rotate_a(t_node **stack);
void	reverse_rotate_b(t_node **stack);
void	swap(t_node **stack, int should_print, char *str); // scambia i primi due elementi della pila
void	swap_a(t_node **stack);
void	rotate_both(t_node **stack_a, t_node **stack_b); // ruota entrambe le pile verso l'alto
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b); // ruota entrambe le pile verso il basso
void    swap_both(t_node **stack_a, t_node **stack_b); // scambia i primi due elementi di entrambe le pile

t_node	*find_min(t_node *stack); // trova il nodo con il valore minimo nella pila
int		find_max(t_node *stack); // trova il valore massimo nella pila
void	calculate_cost(t_node *stack_a, t_node *stack_b); // calcola il costo di ogni nodo nella pila
t_node	*find_next_bigger(t_node *stack, int value); // trova il nodo con il valore più grande successivo a un dato valore
int		find_posix(t_node *stack, int value); // trova la posizione di un valore nella pila
t_node	*get_lowest_cost(t_node *stack); // trova il nodo con il costo totale più basso
void	execute_best_node(t_node **stack_a, t_node **stack_b); // esegue l'operazione migliore basata sul costo totale
void	sort_three(t_node **a); // algoritmo di ordinamento per tre elementi

#endif
