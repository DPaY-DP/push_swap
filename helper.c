# include "push_swap.h"

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
