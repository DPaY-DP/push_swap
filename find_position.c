# include "push_swap.h"

// int	find_position_big(t_Node **stack, int min_value)
// {
// 	t_Node	*current;
// 	t_Node	*start;
// 	int		pos;
// 	int		best_pos;
// 	int		max_val;
// 	int		best_val;
// 	int		has_best;
// 	int		max_index;

// 	if (stack == NULL || *stack == NULL)
// 		return (0);
// 	start = *stack;
// 	current = start;
// 	best_pos = -1;
// 	pos = 0;
// 	max_val = start->data;
// 	best_val = 0;
// 	has_best = 0;
// 	max_index = 1;
// 	if (current->data <	min_value && ((!has_best) || current->data > best_val))
	// 			{
// 				best_val = start->data;
// 				best_pos = 0;
// 				has_best = 1;
// 			}
// 	current = current->next;
// 	while (current != start)
// 		{
// 			if (current->data > max_val)
// 			{
// 				max_val = current->data;
// 				pos = max_index;
// 			}
// 			if (current->data <	min_value && ((!has_best) || current->data > best_val))
// 			{
// 				best_val = current->data;
// 				best_pos = max_index;
// 				has_best = 1;
// 			}
// 			max_index++;
// 			current = current->next;
// 		}
// 	if (has_best == 1)
// 		return (best_pos);
// 	return (pos);
// }
/*Finding the best position on stack b, which is 1 smaller than the min_value given in
Giving back the position of the value on the stack*/
int	find_best_position(t_Node **stack, int max_index, int min_value)
{
	t_Node	*current;
	t_Node	*start;
	int		best_pos;
	int		best_value;

	best_pos = -1;
	start = *stack;
	current = start;
	if (current->data <	min_value && ((best_pos == -1) || current->data > best_value))
			{
				best_value = start->data;
				best_pos = 0;
			}
	current = current->next;
	while (current != start)
	{
		if (current->data <	min_value && ((best_pos == -1) || current->data > best_value))
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



