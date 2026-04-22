# include "push_swap.h"


void	reverse_rotate_loop(t_Node **a, t_Node **b, int b_index, int a_index)
{
	while (b_index > 0 && a_index > 0)
	{
		reverse_rotate_both(a, b);
		a_index--;
		b_index--;
	}
	while (a_index > 0)
	{
		reverse_rotate_a(a);
		a_index--;
	}
	while (b_index-- > 0)
		reverse_rotate_b(b);
}

void	rotate_loop(t_Node **a, t_Node **b, int b_index, int a_index)
{
	while (b_index > 0 && a_index > 0)
	{
		rotate_both(a, b);
		a_index--;
		b_index--;
	}
	while (a_index > 0)
	{
		rotate_a(a);
		a_index--;
	}
	while (b_index-- > 0)
		rotate_b(b);
}

int	move_rotate_forward(t_Node **a, t_Node **b, int a_pos, int min_value)
{
	int	b_pos;
	int	b_lenght;

	b_pos = 0;
	b_lenght = numbers_on_stack(b);
	if (*b != NULL)
		b_pos = find_position_small(b, 1, min_value);
	if (b_pos <= (b_lenght / 2))
		rotate_loop(a, b, b_pos, a_pos);
	else
	{
		b_pos = (b_lenght - b_pos);
		while (b_pos-- > 0)
			reverse_rotate_b(b);
		while (a_pos-- > 0)
			rotate_a(a);
	}
	push_b(a, b);
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
	min_value = (*a)->data;
	return (min_value);
}

int	move_rotate_backward(t_Node **a, t_Node **b, int a_pos, int min_value)
{
	int	b_pos;
	int	b_lenght;

	b_pos = 1;
	b_lenght = numbers_on_stack(b);
	if (*b != NULL)
		b_pos = find_position_small(b, 1, min_value);
	if (b_pos >(b_lenght / 2))
	{
		b_pos = b_lenght - b_pos;
		reverse_rotate_loop(a, b, b_pos, a_pos);
	}
	else
	{
		while (b_pos-- > 0)
			rotate_b(b);
		while (a_pos-- > 0)
			reverse_rotate_a(a);
	}
	push_b(a, b);
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
	min_value = (*a)->data;
	return (min_value);
}

// if (lenght_a != number_given)
// 					max_index = find_position_small(b, 1, min_value);
// 				if (max_index > ((number_given - lenght_a) / 2))
// 				{
// 					max_index = (number_given - lenght_a) - max_index;
// 					reverse_rotate_loop(a, b, max_index, pos);
// 				}
// 				else
// 				{
// 					while (max_index-- > 0)
// 						rotate_b(b);
// 					while (pos-- > 0)
// 						reverse_rotate_a(a);
// 				}
// 				push_b(a, b);
// 				start_a = *a;
// 				if (start_a != NULL)
// 				{
// 					if (start_a->data > start_a->next->data)
// 					{
// 						swap_a(a);
// 						start_a = *a;
// 					}
// 					// current = start_a->next;
// 					min_value = start_a->data;
// 				}
