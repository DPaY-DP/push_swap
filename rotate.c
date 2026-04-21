/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:06:41 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/21 13:06:41 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_Node **head)
{
	t_Node	*first;
	t_Node	*second;
	t_Node	*last;

	if (head == NULL || *head == NULL || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	last = first->prev;
	first->prev = last;
	last->next = first;
	first->next = second;
	second->prev = first;
	*head = second;
}

void	rotate_a(t_Node **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_Node **b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_Node **a, t_Node **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}
