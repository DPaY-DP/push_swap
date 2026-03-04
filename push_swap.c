/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:08:34 by dpfannen          #+#    #+#             */
/*   Updated: 2026/03/04 17:18:42 by dpfannen         ###   ########.fr       */
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

	newt_node = create_node(data);
	if (*head == NULL)
	{
		*head = newt_node;
		return ;
	}
	newt_node->next = *head;
	newt_node->prev = NULL;
	(*head)->prev = newt_node;
	*head = newt_node;
}

void	print_list_forward(t_Node *head)
{
	t_Node	*temp;

	temp = head;
	printf("Forward List: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
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

int	push_swap(int argc, char **argv)
{
	t_Node	*head;

	head = NULL;
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
			insert_at_beginning(&head, ft_atoi(argv[i]));
		}
		print_list_forward(head);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_Node	*head;

	head = NULL;
	push_swap(argc, argv);
	return (0);
}
