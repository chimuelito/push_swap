#include "push_swap.h"

void	split_two(t_data *data)
{
	int	i;
	int	parts;
	int range;

	i = 1;
	parts = get_division(data->size);
	while (i <= parts)
	{
		range = get_range(data->size, parts, i);
		move_lower_values(range - 1, &data->b,  &data->a);
		i++;
	}
	data->b.index_max = data->size - 1;
	data->b.index_min = 0; 
	while (data->b.head != NULL)
		throwback_values(&data->a, &data->b);
	int min_pos = get_target_position(&data->a, data->a.index_min);
	if (min_pos > data->a.size / 2)
		while (data->a.head->index != 0)
			reverse_rotate_stack(&data->a);
	else
		while (data->a.head->index != 0)
			rotate_stack(&data->a);
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
	int div;
	size_t	i;

	i = 0;
	while (i * i <= size)
		i++;
	div = i / 2;
	return (div);
}

void	move_lower_values(int range, t_stack *dst, t_stack *src)
{
	int top;
	int bottom;
	int j;

	top = 0;
	while (top != -1)
	{
		top = get_position_from_top(range, src);
		bottom = get_position_from_bottom(range, src);
		j = -1;
//		printf("top: %d, bottom: %d\n", top, bottom);
		if (top <= bottom)
			while (++j < top)
				rotate_stack(src);
		else
			while (++j <= bottom)
				reverse_rotate_stack(src);
		if (top != -1)
			push(dst, src);
	}
}

int	get_position_from_top(int range, t_stack *s)
{
	t_node	*cursor;
	int		i;
	t_bool	found;

	i = -1;
	found = FALSE;
	cursor = s->head;
	while (cursor && !found)
	{
		if (cursor->index <= range)
			found = TRUE;	
		cursor = cursor->next;
		i++;
	}
	if (found)
		return (i);
	else
		return (-1);
}


int	get_position_from_bottom(int range, t_stack *s)
{
	t_node	*cursor;
	int		i;
	t_bool	found;

	i = -1;
	found = FALSE;
	cursor = s->tail;
	while (cursor && !found)
	{
		if (cursor->index <= range)
			found = TRUE;
		cursor = cursor->prev;
		i++;
	}
	if (found)
		return (i);
	else
		return (-1);
}
