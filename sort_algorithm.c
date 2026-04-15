/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:38 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:38 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:55:39 by marvin            #+#    #+#             */
/*   Updated: 2026/04/14 23:55:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void	sort_algorithm(t_Node **a, t_Node **b, int number_given)
{
	t_Node	*start_a;
	t_Node	*current;
	int		min_value;
	int		lenght_a;
	int		max_index;
	int		pos;
	int		reverse_pos;
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
			pos = 0;
			while (current != start_a && start_a != NULL && max_index < max_rotate)
			{
				if (current->data <	min_value)
				{
					best_direction = 1;
					min_value = current->data;
					pos = max_index;
					max_index++;
				}
				else
					max_index++;
				current = current->next;
			}
			reverse_pos = 0;
			// pos = find_position_small(a, max_index, min_value);
			// best_direction = 1;
			max_index = 1;
			current = start_a->prev;
			while (current != start_a && start_a != NULL && max_index < max_rotate)
			{
				if (current->data <= min_value)
				{
					best_direction = 2;
					min_value = current->data;
					reverse_pos = max_index;
					max_index++;
				}
				else
					max_index++;
				current = current->prev;
			}
			if (lenght_a < max_rotate)
				if (pos < reverse_pos)
					best_direction = 1;
			if 	(best_direction == 1)
			{
				if (lenght_a != number_given)
					max_index = find_position_small(b, 1, min_value);
				if (max_index <= ((number_given - lenght_a)/2))
				{
					while (max_index > 0 && pos > 0)
						{
							rotate_both(a, b);
							pos--;
							max_index--;
						}
					while 	(pos > 0)
					{
						rotate_a(a);
						pos--;
					}
					while (max_index-- > 0)
						rotate_b(b);
				}
				else{
					max_index = (number_given - lenght_a) - max_index;
					while(max_index-- > 0)
						reverse_rotate_b(b);
					while 	(pos > 0)
					{
						rotate_a(a);
						pos--;
					}
				}
				// if (is_sorted(a) == 1)
				// 	return ;
				push_b(a, b);
				// if ((*a) != NULL && ((*a)->data > (*a)->next->data))
				// 	swap_a(a);
				start_a = *a;
				if (start_a != NULL)
					{if (start_a->data > start_a->next->data)
							{swap_a(a);
								start_a = *a;
							}
						current = start_a->next;
					min_value = start_a->data;}
			}
			else
			{
				if (lenght_a != number_given)
					max_index = find_position_small(b, 1, min_value);
				if (max_index > ((number_given - lenght_a)/2))
				{
					max_index = (number_given - lenght_a) - max_index;
					while (max_index > 0 && reverse_pos > 0)
						{
							reverse_rotate_both(a, b);
							reverse_pos--;
							max_index--;
						}
					while 	(reverse_pos > 0)
					{
							reverse_rotate_a(a);
							reverse_pos--;
						}
					while (max_index-- > 0)
						reverse_rotate_b(b);
				}
				else{
					while(max_index-- > 0)
						rotate_b(b);
					while (reverse_pos > 0)
						{
							reverse_rotate_a(a);
							reverse_pos--;
						}
					}
				push_b(a, b);
				// if ((*a) != NULL && ((*a)->data > (*a)->next->data))
				// 	swap_a(a);
				start_a = *a;
				if (start_a != NULL)
					{
						if (start_a->data > start_a->next->data)
							{swap_a(a);
								start_a = *a;
							}
					current = start_a->next;
					min_value = start_a->data;}
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
