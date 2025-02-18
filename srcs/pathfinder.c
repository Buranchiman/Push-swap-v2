#include "push_swap.h"

int	search_top(t_stack *stack, int f(size_t elem, size_t cmp), int cmp)
{
	t_stack	*tmp;
	int		count;

	tmp = stack;
	count = 0;
	while (tmp && !f(tmp->rank, cmp))
	{
		tmp = tmp->next;
		count ++;
	}
	if (!tmp)
		return (-1);
	return (count);
}

t_stack	*set_previous(t_stack *stack, t_stack *elem)
{
	t_stack	*previous;

	previous = stack;
	while (previous->next != elem)
		previous = previous->next;
	return (previous);
}

int	search_bottom(t_stack *stack, int f(size_t elem, size_t cmp), int cmp)
{
	t_stack	*tmp;
	int		count;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	count = 1;
	while (tmp != stack && !f(tmp->rank, cmp))
	{
		tmp = set_previous(stack, tmp);
		count ++;
	}
	if (tmp == stack)
		return (-1);
	return (count);
}

void	fastest_path(t_stack **stack, int f(size_t elem, size_t cmp), t_holder *holder, int cmp)
{
	int	rotate_count;
	int	reverse_rotate_count;
	int	count;

	rotate_count = search_top(*stack, f, cmp);
	reverse_rotate_count = search_bottom(*stack, f, cmp);
	count = 0;
	if (rotate_count <= reverse_rotate_count)
	{
		while (count < rotate_count)
		{
			rotate(stack, holder, 0);
			count++;
		}
	}
	else
	{
		while (count < reverse_rotate_count)
		{
			reverse_rotate(stack, holder, 0);
			count ++;
		}
	}
}
