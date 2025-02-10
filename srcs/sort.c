#include "push_swap.h"

void	sort_three(t_holder **holder)
{
	if (((*holder)->a->rank == 1 && (*holder)->a->next->rank == 3) || ((*stack)->rank == 2 && (*stack)->next->rank == 1) || ((*stack)->rank == 3 && (*stack)->next->rank == 2))
		swap
}

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
