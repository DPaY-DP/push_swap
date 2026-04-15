/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpfannen <dpfannen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:42:49 by dpfannen          #+#    #+#             */
/*   Updated: 2026/04/15 15:42:49 by dpfannen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*main function of push_swap
starting to check and split the first argv
if valid and only 2 arg then do nothing
if more than 2 than put everything on stack a
then sort stack a in main sort_argorithm func
later free everything so no leaks*/
int	push_swap(int argc, char **argv)
{
	t_Node	*a;
	t_Node	*b;
	int		i;
	char	**tab;
	int		length;
	int		j;

	i = 1;
	a = NULL;
	b = NULL;
	j = 0;
	if (argc < 2)
		return (0);
	tab = ft_split(argv[1], ' ');
	if (tab)
		length = ft_strlen(tab);
	else
		length = 0;
	if (argc + length == 3 || argc + length == 2)
	{
		if (is_valid_input(tab[0]) == 0)
			return (free_all_array(tab, length), write(2, "Error\n", 6));
	}
	else
	{
		while (i < argc)
		{
			if (length != 1)
			{
				while (j < length)
				{
					if (is_valid_input(tab[j]) == 0)
						return (free_all(&a), free_all_array(tab, length), 
						write(2, "Error\n", 6));
					if (check_duplicate(a, ft_atoi(tab[j])))
						return (free_all(&a), free_all_array(tab, length), 
						write(2, "Error\n", 6));
					insert_at_end(&a, ft_atoi(tab[j]));
					j++;
				}
				j = 0;
			}
			else
			{
				if (is_valid_input(tab[j]) == 0)
						return (free_all(&a), free_all_array(tab, length), 
						write(2, "Error\n", 6));
					if (check_duplicate(a, ft_atoi(tab[j])))
						return (free_all(&a), free_all_array(tab, length), 
						write(2, "Error\n", 6));
					insert_at_end(&a, ft_atoi(tab[j]));
			}
			i++;
			free_all_array(tab, length);
			tab = ft_split(argv[i], ' ');
			if (tab)
				length = ft_strlen(tab);
		}
		if (is_sorted(&a) == 2)
			sort_algorithm(&a, &b, numbers_on_stack(&a));
		while (b != NULL)
		{
			push_a(&a, &b);
		}		
	}

	// if (is_sorted(&a) == 1)
	// 	printf("sortiert");
	if (tab)
		free_all_array(tab, length);
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
