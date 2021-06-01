#include "push_swap.h"

int	free_and_quit(t_data data, int return_value)
{
	free(data.array);
	dll_lstfree(&data.a.head);
	dll_lstfree(&data.b.head);
	if (return_value == EXIT_FAILURE)
		ft_putstr_fd(ERR_MSG, 2);
	return (return_value);
}

t_bool	is_sorted(t_stack *s)
{
	t_node	*cursor;

	cursor = s->head;
	while (cursor->next)
	{
		if (cursor->index != cursor->next->index - 1)
			return (FALSE);
		cursor = cursor->next;
	}
	return (TRUE);
}

void	print_array(int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf(" %d :", array[i]);
		i++;
	}
	printf("\n");
}

int	get_range(size_t size, int part, int i)
{
	float	frange;

	frange = i * size / (float)part;
	if (frange - (int)frange >= 0.5)
		return ((int)frange + 1);
	else
		return (frange);
}

int	get_division(size_t size)
{
	int		div;
	size_t	i;

	i = 0;
	while (i * i <= size)
		i++;
	div = i / 2;
	return (div);
}
