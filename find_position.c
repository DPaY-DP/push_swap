# include "push_swap.h"

int	find_position_small(t_Node **stack, int max_index, int min_value)
{
	t_Node	*current;
	t_Node	*start;
	int		pos;

	start = *stack;
	current = start->next;
	pos = 0;
	while (current != start && start != NULL && max_index < 11)
		{
			if (current->data <	min_value)
			{
				min_value = current->data;
				pos = max_index;
				max_index++;
			}
			else
				max_index++;
			current = current->next;
		}
	return (pos);
}

int	find_position_big(t_Node **stack, int min_value)
{
	t_Node	*current;
	t_Node	*start;
	int		pos;
	int		best_pos;
	int		max_val;
	int		best_val;
	int		has_best;
	int		max_index;

	if (stack == NULL || *stack == NULL)
		return (0);
	start = *stack;
	current = start;
	best_pos = -1;
	pos = 0;
	max_val = start->data;
	best_val = 0;
	has_best = 0;
	max_index = 1;
	if (current->data <	min_value && ((!has_best) || current->data > best_val))
			{
				best_val = start->data;
				best_pos = 0;
				has_best = 1;
			}
	current = current->next;
	while (current != start)
		{
			if (current->data > max_val)
			{
				max_val = current->data;
				pos = max_index;
			}
			if (current->data <	min_value && ((!has_best) || current->data > best_val))
			{
				best_val = current->data;
				best_pos = max_index;
				has_best = 1;
			}
			max_index++;
			current = current->next;
		}
	if (has_best == 1)
		return (best_pos);
	return (pos);
}
