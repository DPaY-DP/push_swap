/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:44:22 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/01 14:49:39 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
#include "push_swap.h"


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
