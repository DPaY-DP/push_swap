/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:18 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:18 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Debugg-function
Printing out the values on the stack*/
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

/*count how many str on **array*/
size_t	ft_strlen(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*count how many numbers on stack*/
int	numbers_on_stack(t_Node **stack)
{
	t_Node	*start;
	t_Node	*current;
	int		count;

	if (!*stack)
		return (0);
	start = *stack;
	current = start->next;
	count = 1;
	while (current != start)
	{
		count++;
		current = current->next;
	}
	return (count);
}

