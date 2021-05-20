#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define ERR_MSG "Error\n"
# define FAIL	(0)
# define SUCCESS (1)

# define INTMAX_LEN (10)

typedef struct	s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef	struct	s_stacks
{
	int		*array;
	size_t	size;

	t_node	*a_head;
	t_node	*a_tail;

	t_node	*b_head;
	t_node	*b_tail;

}				t_stacks;

int	setup_stacks(int argc, char **argv, t_stacks *stacks);
int	free_and_quit(t_stacks stacks, int return_value);
int	init_stacks(int argc, t_stacks *stacks);
t_bool	is_invalid_entry(long entry, char *str);
int		sort_and_check_unicity(int *array, size_t size);

/*
 * doubly linked list
 *
*/

t_node	*dll_create_node(int val);
void	dll_add_back(t_node **head, t_node *new);
void	dll_add_front(t_node **head, t_node *new);
void	dll_lstfree(t_node **head);
void	dll_print_list(t_node *head);

void	print_array(int *array, size_t size);

# endif
