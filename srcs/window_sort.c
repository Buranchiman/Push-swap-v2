#include "push_swap.h"

void	init_window(t_holder *holder)
{
	int	size;

	holder->window_min  = 0;
	size  = ft_stacksize(holder->a);
	if (size <= 200)
		holder->window_max = size * SMALL_LIST_RATIO;
	else
		holder->window_max = size * BIG_LIST_RATIO;
}

void	in_window_or_smaller(t_holder  *holder)
{
	if (holder->a->rank >= holder->window_min && holder->a->rank <= holder->window_max)
		{
			push(&(holder)->a, &(holder)->b, holder);
			holder->window_min ++;
			holder->window_max ++;
			if (holder->a->rank > holder->window_max)
			{
				rotate(&(holder)->a, holder, 1);
				rotate(&(holder)->b, holder, 2);
			}
			else
				rotate(&(holder)->b, holder, 0);
		}
	if (holder->a->rank < holder->window_min)
	{
		push(&(holder)->a, &(holder)->b, holder);
		holder->window_min ++;
		holder->window_max ++;
	}
}

void	window_sort(t_holder *holder)
{

	init_window(holder);
	while (ft_stacksize(holder->a) > 3 && !ft_sorted(holder->a))
	{
		if (holder->a->rank <= holder->window_max)
			in_window_or_smaller(holder);
		else
		{
			if (ft_stacklast(holder->a)->rank <= holder->window_max)
				reverse_rotate(&(holder)->a, holder, 0);
			else
				rotate(&(holder)->a, holder, 0);
		}
	}
}
