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

// static int	search_position(t_Node *start, int max_rotate, int min_value)
// {
// 	t_Node	*current;
// 	int		index;
// 	int		pos;

// 	current = start->next;
// 	index = 1;
// 	pos = 0;
// 	while (current != start && start != NULL && index < max_rotate)
// 	{
// 		if (current->data <	min_value)
// 		{
// 			min_value = current->data;
// 			pos = index;
// 			index++;
// 		}
// 		else
// 			index++;
// 		current = current->next;
// 	}
// 	return (pos);
// }
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

int	find_next_position_to_rotate(t_Node **a, int max_rotate,
	int *min_value, int lenght_a)
{
	t_Node	*start_a;
	t_Node	*current;
	int		pos;

	start_a = *a;
	current = start_a->next;
	*min_value = start_a->data;
	pos = find_rotate_direction(start_a, max_rotate, min_value, lenght_a);
	return (pos);
}

void	sort_algorithm(t_Node **a, t_Node **b, int number_given)
{
	t_Node	*start_a;
	t_Node	*current;
	int		min_value;
	int		lenght_a;
	int		max_index;
	int		pos;
	int		best_direction;
	int		max_rotate;

	max_index = 1;
	lenght_a = number_given;
	start_a = *a;
	current = start_a->next;
	min_value = start_a->data;
	if (number_given > 250)
		max_rotate = 15;
	else
		max_rotate = 7;
	if (number_given < 4)
		sort_tiny(a, number_given);
	else
	{
		while (lenght_a > 0)
		{
			best_direction = 1;
			pos = find_next_position_to_rotate(a, max_rotate,
					&min_value, lenght_a);
			if (pos < 0)
			{
				pos *= -1;
				best_direction = 2;
			}
			if (best_direction == 1)
			{
				if (lenght_a != number_given)
					max_index = find_position_small(b, 1, min_value);
				if (max_index <= ((number_given - lenght_a) / 2))
					rotate_loop(a, b, max_index, pos);
				else
				{
					max_index = (number_given - lenght_a) - max_index;
					while (max_index-- > 0)
						reverse_rotate_b(b);
					while (pos-- > 0)
						rotate_a(a);
				}
				push_b(a, b);
				start_a = *a;
				if (start_a != NULL)
				{
					if (start_a->data > start_a->next->data)
					{
						swap_a(a);
						start_a = *a;
					}
					current = start_a->next;
					min_value = start_a->data;
				}
			}
			else
			{
				if (lenght_a != number_given)
					max_index = find_position_small(b, 1, min_value);
				if (max_index > ((number_given - lenght_a) / 2))
				{
					max_index = (number_given - lenght_a) - max_index;
					reverse_rotate_loop(a, b, max_index, pos);
				}
				else
				{
					while (max_index-- > 0)
						rotate_b(b);
					while (pos-- > 0)
						reverse_rotate_a(a);
				}
				push_b(a, b);
				start_a = *a;
				if (start_a != NULL)
				{
					if (start_a->data > start_a->next->data)
					{
						swap_a(a);
						start_a = *a;
					}
					current = start_a->next;
					min_value = start_a->data;
				}
			}
			if (is_sorted(a) == 1)
				if (is_sorted_descend(b) == 1)
					return ;
			lenght_a--;
			max_index = 1;
			if (lenght_a < 4)
			{
				sort_tiny(a, lenght_a);
				return ;
			}
		}
	}
}
