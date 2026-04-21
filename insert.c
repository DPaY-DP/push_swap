/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:20 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:20 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*creating the data type t_Node for the linked list*/
t_Node	*create_node(int data)
{
	t_Node	*newt_node;

	newt_node = (t_Node *)malloc(sizeof(t_Node));
	newt_node->data = data;
	newt_node->next = NULL;
	newt_node->prev = NULL;
	return (newt_node);
}

/*putting every given argument number and puttung at the end of stack a*/
// temp = (*head)->prev; //gets tail
// newt_node->next = *head; // new node points to old head
// newt_node->prev = temp; // old head points back to new node
// (*head)->prev = newt_node;
// temp->next = newt_node; // tail points to new head
// *head = newt_node; // new head
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
}

/*atoi function*/
long int	ft_atoi(const char *str)
{
	int				i;
	long long int	nbr;
	int				sign;

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

/*cheching if argument is valid or not
checking if number is over int max or under int min*/
char	is_valid_input(char *c)
{
	long long int	i;

	i = 0;
	if (!c || c[0] == '\0' || ((c[0] == '-' || c[0] == '+') && c[1] == '\0'))
		return (0);
	while (c[i])
	{
		if ((c[i] == '-' && i == 0) || (c[i] == '+' && i == 0))
			i++;
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (0);
		i++;
	}
	i = ft_atoi(c);
	if (i > 2147483647 || i < -2147483648)
		return (0);
	return (1);
}

/*check if a number given is duplicate on the stack*/
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
