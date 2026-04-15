/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:43 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:43 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"
// temp new head
// second is next after old head
// previous 1 points next at 3
//3 now points prev at new 2 
// prevoius 3 points prev at prevoius 1 now 2
// new head is 2 wich is now 1
// prevoius 1, now 2, prev points at new 1
// new 1 prev points at tail
// tail next points at new 1
void	swap_stack(t_Node **stack_head)
{
	t_Node	*head;
	t_Node	*second;
	t_Node	*tail;

	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == *stack_head)
		return ;
	head = *stack_head; 
	tail = (*stack_head)->prev;
	second = head->next; 
	if (tail == second)
	{
		*stack_head = second;
		return ;
	}
	else
	{
	head->next = second->next; 
	head->next->prev = head; 
	second->next = head; 
	*stack_head = second; 
	head->prev = second; 
	second->prev = tail; 
	tail->next = second; 
	}
}

void	swap_a(t_Node **a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_Node **b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}