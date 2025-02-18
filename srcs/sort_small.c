#include "push_swap.h"

void	sort_two(t_holder  *holder)
{
	if (!ft_sorted(holder->a))
		swap(&(holder)->a, holder, 0);
}

void	sort_three(t_holder *holder)
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
void	sort_small(t_holder *holder)
{
	if (ft_stacksize(holder->a) == 3)
		sort_three(holder);
	else if (ft_stacksize(holder->a) == 2)
	{
		sort_two(holder);
		ft_stackclear(&(holder)->a);
		exit (EXIT_SUCCESS);
	}
}
