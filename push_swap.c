/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:44:22 by dpfannen          #+#    #+#             */
/*   Updated: 2026/03/24 18:26:23 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct t_Node {
	int				data;
	struct t_Node	*next;
	struct t_Node	*prev;
}	t_Node;

t_Node	*create_node(int data)
{
	t_Node	*newt_node;

	newt_node = (t_Node *)malloc(sizeof(t_Node));
	newt_node->data = data;
	newt_node->next = NULL;
	newt_node->prev = NULL;
	return (newt_node);
}

void	insert_at_end(t_Node **head, int data)
{
	t_Node	*newt_node;
	t_Node	*temp;

	newt_node = create_node(data);
	if (*head == NULL)
	{
		*head = newt_node;
		newt_node->next = newt_node;
		newt_node->prev = newt_node;
		return ;
	}
	temp = *head;
	while (temp->next != (*head))
		temp = temp->next;
	temp->next = newt_node;
	newt_node->prev = temp;
	newt_node->next = *head;
	(*head)->prev = newt_node;
	// temp = (*head)->prev; //gets tail
	// newt_node->next = *head; // new node points to old head
	// newt_node->prev = temp; // old head points back to new node
	// (*head)->prev = newt_node;
	// temp->next = newt_node; // tail points to new head
	// *head = newt_node; // new head
}

void	rotate_stack(t_Node **head)
{
	t_Node	*first;
	t_Node	*second;
	t_Node	*last;

	if (head == NULL || *head == NULL || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	last = first->prev;
	first->prev = last;
	last->next = first;
	first->next = second;
	second->prev = first;
	*head = second;
}

void	rotate_a(t_Node **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_Node **b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	reverse_rotate_stack(t_Node **head)
{
	t_Node	*first;
	t_Node	*second;
	t_Node	*last;

	if (head == NULL || *head == NULL || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	last = first->prev;
	if (second == last)
	{
		*head = second;
		return ;
	}
	else
	{
	*head = last;
	last->next = first;
	first->prev = last;
	first->next = second;
	second->prev = first;
	}
}

void	reverse_rotate_a(t_Node **a)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_Node **b)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	attach_top(t_Node **dst, t_Node *node)
{
	t_Node	*dst_head;
	t_Node	*dst_tail;

	dst_head = *dst;
	if (dst_head == NULL)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		dst_tail = dst_head->prev;
		node->next = dst_head;
		dst_head->prev = node;
		dst_tail->next = node;
		node->prev = dst_tail;
	}
}

t_Node	*detach_top(t_Node **src)
{
	t_Node	*src_head;
	t_Node	*src_first;
	t_Node	*src_tail;

	src_head = *src;
	if (src_head == NULL)
		return (NULL);
	src_first = src_head->next;
	src_tail = src_head->prev;
	src_first->prev = src_tail;
	src_tail->next = src_first;
	if (src_head == src_first)
		*src = NULL;
	else
		*src = src_first;
	return (src_head);
}

void	push_stack(t_Node **src, t_Node **dst)
{
	t_Node	*src_head;
	t_Node	*dst_head;
	
	if (*src == NULL)
		return ;
	dst_head = *dst;
	src_head = detach_top(src);
	if (src_head == NULL)
		return ;
	attach_top(dst, src_head);
	*dst = src_head;
}

void	push_b(t_Node **a, t_Node **b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}

void	push_a(t_Node **a, t_Node **b)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	swap_stack(t_Node **head)
{
	t_Node	*temp;
	t_Node	*second;
	t_Node	*tail;

	if (head == NULL || *head == NULL || (*head)->next == *head)
		return ;
	temp = *head; // temp new head
	tail = (*head)->prev;
	second = temp->next; // second is next after old head
	if (tail == second)
	{
		*head = second;
		return ;
	}
	else
	{
	temp->next = second->next; // head next is second next
	second->next = temp; // 
	*head = second;
	temp->prev = second;
	second->prev = tail;
	tail->next = second;
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

void	print_list_forward(t_Node *head)
{
	t_Node	*temp;

	temp = head;
	printf("Forward List: ");
	if (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
		while (temp != head)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
	else
		printf(" ");
	printf("\n");
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	if (sign > 1)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	if (sign == 1)
		return (nbr * -1);
	return (nbr);
}

char	is_valid_input(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if ((c[i] == '-' && i == 0) || (c[i] == '+' && i == 0))
		{
			i++;
			continue ;
		}
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	free_all(t_Node **head)
{
	t_Node	*temp;
	t_Node	*last;

	if (head == NULL)
		return;
	if (*head == NULL)
		return ;
	last = (*head)->prev;
	if (last == *head)
	{
		free(*head);
		*head = NULL;
		return ;
	}
	last->next = NULL;
	temp = (*head)->next;
	free(*head);
	while (temp != NULL)
	{
		*head = temp;
		temp = (*head)->next;
		free(*head);
	}
	*head = NULL;
}

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

void	sort_algorithm_push_five(t_Node **a, t_Node **b)
{
	t_Node	*head;
	t_Node	*current;
	int		min_value;
	int		pos;
	int		current_index;

	head = *a;
	current = head->next;
	min_value = head->data;
	pos = 0;
	current_index = 0;
	while (current_index < 5)
	{
		if (current->data < min_value)
			{
				swap_a(a);

				push_b(a, b);
			}
		else
			push_b(a, b);
		head = *a;
		current = head->next;
		min_value = head->data;
		current_index++;
	}
	while (current_index > 0)
	{
		push_a(a, b);
		current_index--;
	}
	
	if (is_sorted(a) == 1)
		return
	// rotate_a(a);
	// rotate_a(a);
	sort_algorithm_push_five(a, b);
}
int	find_position_small(t_Node **stack, int max_index, int min_value)
{
	t_Node	*current;
	t_Node	*start;
	int		pos;

	start = *stack;
	current = start->next;
	pos = 0;
	while (current != start && start != NULL)
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
	// best_val = 0;
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


void	sort_algorithm(t_Node **a, t_Node **b, int number_given)
{
	t_Node	*start_a;
	// t_Node	*start_b;
	t_Node	*current;
	int		min_value;
	int		lenght_a;
	int		max_index;
	int		pos;

	max_index = 1;
	pos = 0;
	lenght_a = number_given;
	// count_b = 0;
	start_a = *a;
	current = start_a->next;
	min_value = start_a->data;
	// print_list_forward(*a);
	// start_b = *b;
	if (number_given <= 500)
	{
		while (lenght_a > 0)
		{
			while (current != start_a && start_a != NULL && max_index < 11)
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
			if 	((pos <= (lenght_a / 2)))
			{
				// printf("rotate \n");
				while 	(pos > 0)
				{
					rotate_a(a);
					pos--;
				}
				if (lenght_a != number_given)
					{
						// printf("\n");
						pos = find_position_big(b, min_value);
						// printf("%d", pos);
						if (pos <= ((number_given - lenght_a)/2))
							{
								while (pos-- > 0)
									rotate_b(b);
							}
						else{
								pos = (number_given - lenght_a) - pos;
								while(pos-- > 0)
									reverse_rotate_b(b);
							}
					}
				push_b(a, b);
				start_a = *a;
				if (start_a != NULL)
					{current = start_a->next;
					min_value = start_a->data;}
				// print_list_forward(*a);
				// print_list_forward(*b);
				// printf("\n");
			}
			else
			{
				// printf("reverse ");
				while (pos < lenght_a)
				{
					reverse_rotate_a(a);
					pos++;
				}
				if (lenght_a != number_given)
					{
						pos = find_position_big(b, min_value);
						// printf("%d", pos);
						if (pos <= ((number_given - lenght_a)/2))
							{
								while (pos-- > 0)
									rotate_b(b);
							}
						else{
								pos = (number_given - lenght_a) - pos;
								while(pos-- > 0)
									reverse_rotate_b(b);
							}
					}
				push_b(a, b);
				start_a = *a;
				if (start_a != NULL)
					{current = start_a->next;
					min_value = start_a->data;}
				// print_list_forward(*a);
				// print_list_forward(*b);
				// printf("\n");
			}
			if (is_sorted(a) == 1)
				if (is_sorted_descend(b) == 1)
					return ;
			lenght_a--;
				// max_index = pos;
					// swap_b(b);
			// if (is_sorted(b) == 2)
			// {
			// 				// if ((*b)->data < (*b)->next->data)
			// 				// {
			// 				if (number_given - lenght_a > 3)
			// 					{pos = find_position_big(b, 1, (*b)->data);
			// 					if (pos == 1)
			// 						swap_b(b);}
			// 			// 	if (is_sorted_descend(b) == 2)
			// 			// 		{
			// 			// // 			pos = find_position_small(b, 1, (*b)->data);
			// 			// // 			if (pos <= ((number_given - lenght_a)/2))
			// 			// // 				{
			// 			// // 					while ((pos + 1) > 0)
			// 			// // 					{
			// 			// // 						rotate_b(b);
			// 			// // 						// if ((*b)->data < (*b)->next->data)
			// 			// // 						// 	swap_b(b);
			// 			// // 						pos--;
			// 			// // 					}
			// 			// // 				}
			// 			// // 			else{
			// 			// // 					while((pos - 1) < (number_given - lenght_a))
			// 			// // 					{
			// 			// // 						reverse_rotate_b(b);
			// 			// // 						// if ((*b)->data < (*b)->next->data)
			// 			// // 						// 	swap_b(b);
			// 			// // 						pos++;
			// 			// // 					}
			// 			// // 				}
			// 			// // 		// }
			// 			// // }
									
			// 			// 		}
			// }
			max_index = 1;
			// printf("%d true lenght\n", lenght_a);
			// printf("banane\n");
		}
	}
	// printf("%d test test\n", lenght_a);
	// printf("%d",	max_index);
}

int	push_swap(int argc, char **argv)
{
	t_Node	*a;
	t_Node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (is_valid_input(argv[1]) == 0)
			return (write(1, "Error", 5));
		// Process the single argument case
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (is_valid_input(argv[i]) == 0)
				return (write(1, "Error", 5));
			insert_at_end(&a, ft_atoi(argv[i]));
		}
		// sort_algorithm_push_five(&a, &b);
		// print_list_forward(a);
		// print_list_forward(b);
		sort_algorithm(&a, &b, (argc - 1));
		// print_list_forward(b);
		while (b != NULL)
		{
			push_a(&a, &b);
		}
		// printf("gurke");
		// print_list_forward(a);
		// print_list_forward(b);
		// for (int i = 0; i < 2; i++)
		// {
		// 	push_b(&a, &b);
		// 	print_list_forward(a);
		// 	printf("b_ ");
		// 	print_list_forward(b);
		// 	// print_list_forward(a);
		// 	// reverse_rotate_a(&a);
		// }
		// // print_list_forward(head);
		// swap_a(&a);
		// print_list_forward(a);
		// print_list_forward(b);
		// swap_b(&b);
		// print_list_forward(a);
		// print_list_forward(b);
		// swap_a(&head);
		// print_list_forward(head);
		// rotate_a(&head);
		// print_list_forward(head);
		// rotate_a(&head);
		// print_list_forward(head);
		// swap_a(&head);
		// print_list_forward(head);
		
	}
	if (is_sorted(&a) == 1)
		printf("sortiert");
	free_all(&a);
	free_all(&b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_Node	*head;

	head = NULL;
	push_swap(argc, argv);
	return (0);
}
