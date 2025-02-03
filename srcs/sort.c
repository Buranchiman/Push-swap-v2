#include "push_swap.h"

void	sortstack(t_holder *holder)
{
	int	window_min;
	int	window_max;

	window_min = 1;
	window_max = ft_stacksize(holder->a) / 10;
	while (ft_stacksize(holder->a) > 3)
	{
		if (holder->a->rank >= window_min && holder->a->rank <= window_max)
		{
			push(&(holder)->a, &(holder)->b, "pb");
			window_min ++;
			window_max ++;
			if (holder->a->rank > window_max)
			{
				rotate(&(holder)->a, NULL);
				rotate(&(holder)->b, "rr");
			}
			else
				rotate(&(holder)->b, "rb");
		}
	}
}
