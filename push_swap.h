
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_Node {
    int				data;
    struct t_Node	*next;
    struct t_Node	*prev;
}	t_Node;

t_Node	    *create_node(int data);
void	    insert_at_end(t_Node **head, int data); 
void	    rotate_stack(t_Node **head);
void	    reverse_rotate_stack(t_Node **head);
void	    swap_stack(t_Node **head);
void	    push_stack(t_Node **src, t_Node **dst);
void	    push_a(t_Node **a, t_Node **b);
void	    push_b(t_Node **a, t_Node **b);
void	    swap_a(t_Node **a);
void	    swap_b(t_Node **b);
void	    rotate_a(t_Node **a);
void	    rotate_b(t_Node **b);
void	    reverse_rotate_a(t_Node **a);
void	    reverse_rotate_b(t_Node **b);
void	    rotate_both(t_Node **a, t_Node **b);
void	    reverse_rotate_both(t_Node **a, t_Node **b);
void	    sort_tiny(t_Node **a, int stack_lenght);
void	    sort_algorithm(t_Node **a, t_Node **b, int number_given);
int		    find_position_big(t_Node **stack, int min_value);
int		    find_position_small(t_Node **stack, int max_index, int min_value);
int		    is_sorted(t_Node **a);
int		    is_sorted_descend(t_Node **b);
int		    check_duplicate(t_Node *a, int num);
char		is_valid_input(char *str);
long int	ft_atoi(const char *str);
void	    free_all(t_Node **head);
int         find_best_position(t_Node **stack, int start_pos, int value);
void	    print_list_forward(t_Node *head);

#endif