# include "push_swap.h"

void	sort_tiny(t_Node **a, int stack_lenght)
{
	int		highest_pos;
	int		sorted;

	sorted = is_sorted(a);
	if (sorted == 1)
		return ;
	if (stack_lenght == 2)
		return (swap_a(a));
	highest_pos = find_position_big(a, -2147483648);
	if (highest_pos == 0)
		rotate_a(a);
	else if (highest_pos == 1)
		reverse_rotate_a(a);
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
}
