#include "push_swap.h"

size_t	smallest_elem(t_stack *stack)
{
	t_stack	*tmp;
	size_t	smallest;

	tmp = stack;
	smallest = tmp->rank;
	while (tmp)
	{
		if (tmp->rank < smallest)
			smallest = tmp->rank;
		tmp = tmp->next;
	}
	return (smallest);
}

size_t	biggest_elem(t_stack	*stack)
{
	t_stack		*tmp;
	size_t		biggest;

	tmp = stack;
	biggest = tmp->rank;
	while (tmp)
	{
		if (tmp->rank > biggest)
			biggest = tmp->rank;
		tmp = tmp->next;
	}
	return (biggest);
}
void	three_ordered(t_holder *holder)
{
	t_stack	*second;
	t_stack	*third;
	int		smallest;

	second = holder->a->next;
	third = second->next;
	if (third->rank > holder->a->rank && second->rank > third->rank)
		swap(&holder->a, holder, 0);
	else if (holder->a->rank > second->rank && holder->a->rank < third->rank)
		swap(&holder->a, holder, 0);
	else if (holder->a->rank > second->rank && second->rank > third->rank)
		swap(&holder->a, holder, 0);
	smallest = smallest_elem(holder->a);
	fastest_path(&holder->a, ft_equals, holder, smallest);
}
