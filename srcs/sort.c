#include "push_swap.h"

int	ft_smaller(int i, int max)
{
	if (i < max)
		return (1);
	else
		return (0);
}

int	ft_equals(int testing_value, int reference)
{
	if (testing_value == reference)
		return (1);
	return (0);
}

void	sortstack(t_holder *holder)
{
	int	window_min;
	int	window_max;

	window_min = 1;
	window_max = ft_stacksize(holder->a) / 8;
	while (ft_stacksize(holder->a) > 3)
	{
		if (holder->a->rank >= window_min && holder->a->rank <= window_max)
		{
			push(&(holder)->a, &(holder)->b, holder);
			window_min ++;
			window_max ++;
			if (holder->a->rank > window_max)
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
			window_max ++;
		}
		else
			fastest_path(&(holder)->a, ft_smaller, holder, window_max);
	}
}

void	refill_a(t_holder *holder)
{
	int	biggest;

	while (ft_stacksize(holder->b))
	{
		biggest = biggest_elem(holder->b);
		fastest_path(&holder->b, ft_equals, holder, biggest);
		if (fastest_path(&holder->a, ft_equals, holder, biggest + 1) == -1)
			fastest_path(&holder->a, ft_equals, holder, smallest_elem(holder->a));
		push(&holder->b, &holder->a, holder);
	}
}
