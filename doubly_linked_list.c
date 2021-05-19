#include "push_swap.h"

t_node	*dll_create_node(int val)
{
	t_node *tmp;

	tmp = malloc(sizeof(t_node));
	if (tmp)
	{
		tmp->value = val;
		tmp->prev = NULL;
		tmp->next = NULL;
	}
	return (tmp);
}

void	dll_add_back(t_node **head, t_node *new)
{
	t_node	*cursor;

	if (!head || !new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	cursor = *head;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new;
	new->prev = cursor;
}

void	dll_add_front(t_node **head, t_node *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
}

void	dll_lstfree(t_node **head)
{
	t_node	*cursor;
	t_node	*next;

	if (!head || *head == NULL)
		return ;
	cursor = *head;
	while (cursor)
	{
		next = cursor->next;
		free(cursor);
		cursor = next;
	}
	*head = NULL;
}

/* debug */

void	dll_print_list(t_node *head)
{
	t_node	*cursor;

	if (!head)
		return ;
	cursor = head;
	while (cursor)
	{
		printf(" %d |", cursor->value);
		cursor = cursor->next;
	}
	printf("\n");
}
