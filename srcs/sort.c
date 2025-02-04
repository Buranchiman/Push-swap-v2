#include "push_swap.h"

int	ft_smaller(int i, int max)
{
	if (i < max)
		return (1);
	else
		return (0);
}

void	sortstack(t_holder *holder)
{
	int	window_min;

	window_min = 1;
	holder->window_max = ft_stacksize(holder->a) / 10;
	while (ft_stacksize(holder->a) > 3)
	{
		if (holder->a->rank >= window_min && holder->a->rank <= holder->window_max)
		{
			push(&(holder)->a, &(holder)->b, holder);
			window_min ++;
			holder->window_max ++;
			if (holder->a->rank > holder->window_max)
			{
				rotate(&(holder)->a, holder, 1);
				rotate(&(holder)->b, holder, 2);
			}
			else
				rotate(&(holder)->b, holder, 0);
		}
		else if (holder->a->rank < window_min)
		{
			push(&(holder)->a, &(holder)->b, holder);
			window_min ++;
			holder->window_max ++;
		}
		else
			fastest_path(&(holder)->a, ft_smaller, holder);
	}
}
