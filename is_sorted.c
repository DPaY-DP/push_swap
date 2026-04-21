/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:23 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:23 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*checking if the stack is sorted in ascended order*/
int	is_sorted(t_Node **a)
{
	t_Node	*current;
	t_Node	*head;

	if (a == NULL || *a == NULL)
		return (1);
	head = *a;
	current = head;
	while (current->next != head)
	{
		if (current->data < current->next->data)
			current = current->next;
		else
			return (2);
	}
	return (1);
}

/*check if the stack is sorted in descended order*/
int	is_sorted_descend(t_Node **a)
{
	t_Node	*current;
	t_Node	*head;

	if (a == NULL || *a == NULL)
		return (1);
	head = *a;
	current = head;
	while (current->next != head)
	{
		if (current->data > current->next->data)
			current = current->next;
		else
			return (2);
	}
	return (1);
}
