/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:44:22 by dpfannen          #+#    #+#             */
/*   Updated: 2026/03/12 15:43:25 by dpfannen         ###   ########.fr       */
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

void	insert_at_beginning(t_Node **head, int data)
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
	temp = (*head)->prev; //gets tail
	newt_node->next = *head; // new node points to old head
	newt_node->prev = temp; // old head points back to new node
	(*head)->prev = newt_node;
	temp->next = newt_node; // tail points to new head
	*head = newt_node; // new head
}

void	rotate_stack(t_Node **head)
{
	t_Node	*first;
	t_Node	*second;
	t_Node	*last;

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
}

void	rotate_b(t_Node **b)
{
	rotate_stack(b);
}

void	reverse_rotate_stack(t_Node **head)
{
	t_Node	*first;
	t_Node	*second;
	t_Node	*last;

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
}

void	reverse_rotate_b(t_Node **b)
{
	reverse_rotate_stack(b);
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
}

void	push_a(t_Node **a, t_Node **b)
{
	push_stack(b, a);
}

void	swap_stack(t_Node **head)
{
	t_Node	*temp;
	t_Node	*second;
	t_Node	*tail;

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
}

void	swap_b(t_Node **b)
{
	swap_stack(b);
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
		printf("");
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

void	sort_algorithm(t_Node **a, t_Node **b, int number_given)
{
	t_Node	*start_a;
	// t_Node	*start_b;
	t_Node	*current;
	int		max_value;
	int		i;
	int		max_index;

	max_index = 0;
	i = 0;
	// count_b = 0;
	start_a = *a;
	current = start_a->next;
	max_value = start_a->data;
	// start_b = *b;
	if (number_given <= 5)
	{
		while (i > -1)
		{
			while (current != start_a)
			{
				if (current->data > max_value)
				{
					max_value = current->data;
					max_index++;
				}
				current = current->next;
				i++;
				
				// while (current->data > start_a->next->data)
				// {
				// 	rotate_a(a);
				// 	start_a = *a;
				// 	printf("test\n");
				// 	print_list_forward(*a);
				// 	print_list_forward(*b);
				// 	printf("------------\n");
				// }
				// push_b(a, b);
				// print_list_forward(*a);
				// print_list_forward(*b);
				// printf("------------\n");
			}
			if (max_index <= i / 2)
			{
				while (max_index > 0)
				{
					rotate_a(a);
					max_index--;
				}
				push_b(a, b);
			}
			else
			{
				while (i - max_index > 0)
				{
					reverse_rotate_a(a);
					max_index--;
				}
				push_b(a, b);
			}
			i--;
		}
	}
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
			insert_at_beginning(&a, ft_atoi(argv[i]));
		}
		sort_algorithm(&a, &b, argc);
		print_list_forward(a);
		print_list_forward(b);
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
