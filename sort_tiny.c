/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:40 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:40 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tiny(t_Node **a, int stack_lenght)
{
	int		highest_pos;
	int		sorted;

	sorted = is_sorted(a);
	if (sorted == 1)
		return ;
	if (stack_lenght == 2)
		return (swap_a(a));
	highest_pos = find_position_small(a, 1, -2147483648);
	if (highest_pos == 0)
		rotate_a(a);
	else if (highest_pos == 1)
		reverse_rotate_a(a);
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
}
