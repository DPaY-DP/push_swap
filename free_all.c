/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:26:15 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 12:26:15 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Free everything on the stacks*/
void	free_all(t_Node **head)
{
	t_Node	*temp;
	t_Node	*last;

	if (head == NULL)
		return ;
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
