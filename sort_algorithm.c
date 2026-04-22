/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:43:12 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 15:43:12 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	find_reverse_direction(t_Node *start_a,
	int max_rotate, int *min_value)
{
	t_Node	*current;
	int		reverse_pos;
	int		index;

	current = start_a->prev;
	index = 1;
	reverse_pos = 0;
	while (current != start_a && start_a != NULL && index < max_rotate)
	{
		if (current->data <= *min_value)
		{
			*min_value = current->data;
			reverse_pos = index;
			index++;
		}
		else
			index++;
		current = current->prev;
	}
	return (reverse_pos * -1);
}

static int	find_rotate_direction(t_Node *start_a, int max_rotate,
	int *min_value, int lenght_a)
{
	int		index;
	int		pos;
	int		reverse_pos;
	t_Node	*current;

	index = 1;
	pos = 0;
	current = start_a->next;
	while (current != start_a && start_a != NULL && index < max_rotate)
	{
		if (current->data < *min_value)
		{
			*min_value = current->data;
			pos = index;
		}
		index++;
		current = current->next;
	}
	reverse_pos = find_reverse_direction(start_a, max_rotate, min_value);
	if (lenght_a < max_rotate && pos < (reverse_pos * -1))
		return (pos);
	if (reverse_pos < 0)
		return (reverse_pos);
	return (pos);
}

static int	find_next_position_to_rotate(t_Node **a, int max_rotate,
	int *min_value, int lenght_a)
{
	t_Node	*start_a;
	int		pos;

	start_a = *a;
	*min_value = start_a->data;
	pos = find_rotate_direction(start_a, max_rotate, min_value, lenght_a);
	return (pos);
}

void	sort_algorithm(t_Node **a, t_Node **b, int lenght_a,
		int max_rotate)
{
	int		min_value;
	int		pos;

	min_value = (*a)->data;
	while (lenght_a > 3)
	{
		pos = find_next_position_to_rotate(a, max_rotate,
				&min_value, lenght_a);
		if (pos < 0)
		{
			pos *= -1;
			min_value = move_rotate_backward(a, b, pos, min_value);
		}
		else
			min_value = move_rotate_forward(a, b, pos, min_value);
		if (is_sorted(a) == 1)
			if (is_sorted_descend(b) == 1)
				return ;
		lenght_a--;
	}
	if (lenght_a < 4)
		sort_tiny(a, lenght_a);
}

