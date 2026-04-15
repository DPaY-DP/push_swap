/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:34 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:34 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	reverse_rotate_stack(t_Node **head)
{
	t_Node	*first;
	t_Node	*second;
	t_Node	*last;

	if (head == NULL || *head == NULL || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	last = first->prev;
	if (second == last)
	{
		*head = second;
		return ;
	}
	else
	{
	*head = last;
	last->next = first;
	first->prev = last;
	first->next = second;
	second->prev = first;
	}
}

void	reverse_rotate_a(t_Node **a)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_Node **b)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_Node **a, t_Node **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}
