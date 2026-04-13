# include "push_swap.h"

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
