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

void	rotate_both(t_Node **a, t_Node **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
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

void	reverse_rotate_both(t_Node **a, t_Node **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
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
	
	if (*src == NULL)
		return ;
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

long int	ft_atoi(const char *str)
{
	int			i;
	long int	nbr;
	int			sign;

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
	long int	i;

	i = 0;
	if (!c || c[0] == '\0' || ((c[0] == '-' || c[0] == '+') && c[1] == '\0'))
		return (0);
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
	i = ft_atoi(c);
	// printf("%ld", i);
	if (i > 2147483647 || i < -2147483648)
		return (0);
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

	reverse_pos = 0;
	max_index = 1;
	pos = 0;
	lenght_a = number_given;
	start_a = *a;
	current = start_a->next;
	min_value = start_a->data;
	best_direction = 1;
	if (number_given < 4)
		sort_tiny(a, number_given);
	else
	{
		while (lenght_a > 0)
		{
			// while (current != start_a && start_a != NULL && max_index < 11)
			// {
			// 	if (current->data <	min_value)
			// 	{
			// 		best_direction = 1;
			// 		min_value = current->data;
			// 		pos = max_index;
			// 		max_index++;
			// 	}
			// 	else
			// 		max_index++;
			// 	current = current->next;
			// }
			pos = find_position_small(a, max_index, min_value);
			max_index = 1;
			current = start_a->prev;
			while (current != start_a && start_a != NULL && max_index < 11)
			{
				if (current->data <	min_value)
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
			if 	((best_direction == 1))
			{
				if (lenght_a != number_given)
					max_index = find_position_big(b, min_value);
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
				if (is_sorted(a) == 1)
					return ;
				push_b(a, b);
				start_a = *a;
				if (start_a != NULL)
					{current = start_a->next;
					min_value = start_a->data;}
			}
			else
			{
				if (lenght_a != number_given)
					max_index = find_position_big(b, min_value);
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
				start_a = *a;
				if (start_a != NULL)
					{current = start_a->next;
					min_value = start_a->data;}
			}
			if (is_sorted(a) == 1)
				if (is_sorted_descend(b) == 1)
					return ;
			lenght_a--;
			max_index = 1;
		}
	}
}

int	check_duplicate(t_Node *a, int num)
{
	t_Node	*temp;

	if (a == NULL)
		return (0);
	temp = a;
	while (temp->next != a)
	{
		if (temp->data == num)
			return (1);
		temp = temp->next;
	}
	if (temp->data == num)
		return (1);
	return (0);
}

int	push_swap(int argc, char **argv)
{
	t_Node	*a;
	t_Node	*b;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (is_valid_input(argv[1]) == 0)
			return (write(2, "Error\n", 6));
		// Process the single argument case
	}
	else
	{
		while (i < argc)
		{
			if (is_valid_input(argv[i]) == 0)
				return (free_all(&a), write(2, "Error\n", 6));
			if (check_duplicate(a, ft_atoi(argv[i])))
				return (free_all(&a), write(2, "Error\n", 6));
			insert_at_end(&a, ft_atoi(argv[i]));
			i++;
		}
		if (is_sorted(&a) == 2)
			sort_algorithm(&a, &b, (argc - 1));
		while (b != NULL)
		{
			push_a(&a, &b);
		}		
	}
	// if (is_sorted(&a) == 1)
	// 	printf("sortiert");
	free_all(&a);
	free_all(&b);
	return (0);
}

int	main(int argc, char **argv)
{
	// t_Node	*head;

	// head = NULL;
	push_swap(argc, argv);
	return (0);
}
