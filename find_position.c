/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:12 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:12 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_start_position_helper(t_Node **stack, int min_value)
{
	t_Node	*start;
	int		best_value;
	int		best_pos;

	best_pos = -1;
	best_value = -2147483648;
	start = *stack;
	if (start->data < min_value && ((best_pos == -1) 
		|| start->data > best_value))
			{
				best_value = start->data;
				best_pos = 0;
			}
	return (best_pos);
}

/*Finding the best position on stack b, which is 1 smaller 
than the min_value given in
Giving back the position of the value on the stack*/
int	find_best_position(t_Node **stack, int max_index, int min_value)
{
	t_Node	*current;
	t_Node	*start;
	int		best_pos;
	int		best_value;

	start = *stack;
	best_value = -2147483648;
	best_pos = check_start_position_helper(stack, min_value);
	if (best_pos == 0)
		best_value = start->data;
	current = start->next;
	while (current != start)
	{
		if (current->data <	min_value && ((best_pos == -1) 
			|| current->data > best_value))
			{
				best_value = current->data;
				best_pos = max_index;
			}
			max_index++;
			current = current->next;
	}
	return (best_pos);
}
/*Finding the biggst position on the stack an calling 
the search for the 1 smaller position on the stack.
Returning the best_pos if there or the position of biggest*/
int	find_position_small(t_Node **stack, int max_index, int min_value)
{
	t_Node	*current;
	t_Node	*start;
	int		pos;
	int		best_pos;
	int		max_value;

	// if (stack == NULL || *stack == NULL)
	// 	return (0);
	start = *stack;
	current = start->next;
	pos = 0;
	max_value = start->data;
	while (current != start && start != NULL)
		{
			if (current->data >	max_value)
			{
				max_value = current->data;
				pos = max_index;
			}
			max_index++;
			current = current->next;
		}
	best_pos = find_best_position(stack, 1, min_value);
	if (best_pos != -1)
		return (best_pos);
	return (pos);
}



