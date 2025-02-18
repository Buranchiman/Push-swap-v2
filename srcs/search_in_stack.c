#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

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
