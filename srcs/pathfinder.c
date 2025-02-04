#include "push_swap.h"

int	search_top(t_stack *stack, int f(int elem, int cmp), int cmp)
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

int	search_bottom(t_stack *stack, int f(int elem, int cmp), int cmp)
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
	return (count);
}

void	fastest_path(t_stack **stack, int f(int elem, int cmp), t_holder *holder)
{
	int	rotate_count;
	int	reverse_rotate_count;
	int	count;

	rotate_count = search_top(*stack, f, holder->window_max);
	reverse_rotate_count = search_bottom(*stack, f, holder->window_max);
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
