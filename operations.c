#include "push_swap.h"

void	swap(t_stack *s)
{
	t_node	*second;

	if (!s || !s->head || !s->head->next)
		return ;
	second = s->head->next;
	if (second->next)
		second->next->prev = s->head;
	else
		s->tail = s->head;
	s->head->next = second->next;
	s->head->prev = second;
	second->next = s->head;	
	second->prev = NULL;
	s->head = second;
	print_operation("s", s->name);
}

void	reverse_rotate_stack(t_stack *s)
{
	t_node	*new_tail;

	if (!s || !s->head || s->head == s->tail)
		return ;
	new_tail = s->tail->prev;
	s->tail->next = s->head;
	s->tail->prev = NULL;
	s->head->prev = s->tail;	
	s->head = s->tail;
	s->tail = new_tail;
	s->tail->next = NULL;
	print_operation("rr", s->name);
}

void	rotate_stack(t_stack *s)
{
	t_node	*new_head;

	if (!s || !s->head || s->head == s->tail)
		return ;
	new_head = s->head->next;
	s->head->next = NULL;
	s->head->prev = s->tail;
	s->tail->next = s->head;
	s->tail = s->head;
	s->head = new_head;
	new_head->prev = NULL;
	print_operation("r", s->name);
}

/* pa : push b to a --> push(a, b)
 * pb : push a to b --> push(b, a)
*/
void	push(t_stack *dst, t_stack *src)
{
	t_node	*new_src_head;

	if (!dst || !src || !src->head)
		return ;
	new_src_head = src->head->next;
	if (dst->head)
		dst->head->prev = src->head;
	src->head->next = dst->head; // now src_head is on dst
	dst->head = src->head;
	if (new_src_head)
		new_src_head->prev = NULL;
	src->head = new_src_head;
	if (dst->tail == NULL)
		dst->tail = dst->head;
	print_operation("p", dst->name);
	dst->size++;
	src->size--;
	if (src->size == 0)
		src->tail = NULL;
}

void	print_operation(char *op, char stack_name)
{
	printf("%s%c\n", op, stack_name);
}
