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

static int	insert_on_stack(t_Node **a, char **tab, int length)
{
	int	j;

	j = 0;
	while (j < length)
	{
		if (is_valid_input(tab[j]) == 0)
			return (-1);
		if (check_duplicate(*a, ft_atoi(tab[j])))
			return (-1);
		insert_at_end(a, ft_atoi(tab[j++]));
	}
	return (0);
}

static int	init_list(t_Node **a, int argc, char **argv,
	char **tab)
{
	int		i;
	int		length;
	int		j;

	i = 1;
	tab = ft_split(argv[1], ' ');
	if (tab)
		length = ft_strlen(tab);
	while (i < argc)
	{
		j = insert_on_stack(a, tab, length);
		if (j == -1)
			return (-1);
		free_all_array(tab, length);
		tab = ft_split(argv[++i], ' ');
		if (tab)
			length = ft_strlen(tab);
	}
	return (0);
}

/*main function of push_swap
starting to check and split the first argv
if valid and only 2 arg then do nothing
if more than 2 than put everything on stack a
then sort stack a in main sort_argorithm func
later free everything so no leaks*/
int	push_swap(int argc, char **argv, t_Node **a)
{
	char	**tab;
	int		length;

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
			return (free_all_array(tab, length), -1);
	}
	else
		if (init_list(a, argc, argv, tab) == -1)
			return (free_all_array(tab, length), -1);
	if (tab)
		free_all_array(tab, length);
	return (0);
}

int	main(int argc, char **argv)
{
	t_Node	*a;
	t_Node	*b;
	int		max_rotate;

	a = NULL;
	b = NULL;
	if (push_swap(argc, argv, &a) == -1)
		return (free_all(&a), write(2, "Error\n", 6));
	if (a != NULL && numbers_on_stack(&a) > 250)
		max_rotate = 15;
	else
		max_rotate = 7;
	if (is_sorted(&a) == 2)
		sort_algorithm(&a, &b, numbers_on_stack(&a), max_rotate);
	while (b != NULL)
		push_a(&a, &b);
	free_all(&a);
	free_all(&b);
	return (0);
}
