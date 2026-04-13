
# include "push_swap.h"

void	swap_stack(t_Node **stack_head)
{
	t_Node	*head;
	t_Node	*second;
	t_Node	*tail;

	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == *stack_head)
		return ;
	head = *stack_head; // temp new head
	tail = (*stack_head)->prev;
	second = head->next; // second is next after old head
	if (tail == second)
	{
		*stack_head = second;
		return ;
	}
	else
	{
	head->next = second->next; // previous 1 points next at 3
	head->next->prev = head; //3 now points prev at new 2 
	second->next = head; // prevoius 3 points prev at prevoius 1 now 2
	*stack_head = second; // new head is 2 wich is now 1
	head->prev = second; // prevoius 1, now 2, prev points at new 1
	second->prev = tail; // new 1 prev points at tail
	tail->next = second; // tail next points at new 1
	}
}

void	swap_a(t_Node **a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_Node **b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}