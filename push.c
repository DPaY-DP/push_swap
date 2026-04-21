/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:31 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:31 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*taking the given node and attach it on the top of the wanted stack
link all nodes correctly in both directions*/
void	attach_top(t_Node **dst, t_Node *node)
{
	t_Node	*dst_head;
	t_Node	*dst_tail;

	dst_head = *dst;
	if (dst_head == NULL)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		dst_tail = dst_head->prev;
		node->next = dst_head;
		dst_head->prev = node;
		dst_tail->next = node;
		node->prev = dst_tail;
	}
}

/*taking the top node and link the others correctly so the second node 
is the new current head of the source stack and return the old head*/
t_Node	*detach_top(t_Node **src)
{
	t_Node	*src_head;
	t_Node	*src_first;
	t_Node	*src_tail;

	src_head = *src;
	if (src_head == NULL)
		return (NULL);
	src_first = src_head->next;
	src_tail = src_head->prev;
	src_first->prev = src_tail;
	src_tail->next = src_first;
	if (src_head == src_first)
		*src = NULL;
	else
		*src = src_first;
	return (src_head);
}

/*take head of source and put on destination stack*/
void	push_stack(t_Node **src, t_Node **dst)
{
	t_Node	*src_head;

	if (*src == NULL)
		return ;
	src_head = detach_top(src);
	if (src_head == NULL)
		return ;
	attach_top(dst, src_head);
	*dst = src_head;
}

void	push_a(t_Node **a, t_Node **b)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_Node **a, t_Node **b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}
