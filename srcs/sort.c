#include "push_swap.h"

int	sort_finished(t_holder *holder)
{
	t_stack	*tmp;
	size_t	count;

	if (ft_stacksize(holder->b) == 0)
	{
		tmp = holder->a;
		count = 0;
		while (tmp->next)
		{
			if (tmp->rank != count)
				return (0);
			count++;
			tmp = tmp->next;
		}
		if (tmp->rank != count)
			return (0);
		return (1);
	}
	return (0);
}

int	ft_smaller(size_t i, size_t max)
{
	if (i <= max)
		return (1);
	else
		return (0);
}

int	ft_equals(size_t testing_value, size_t reference)
{
	if (testing_value == reference)
		return (1);
	return (0);
}

void	sortstack(t_holder *holder)
{
	size_t	window_min;
	size_t	window_max;
	float	ratio;

	window_min = 0;
	if (ft_stacksize(holder->a) <= 200)
		ratio = 0.1;
	else
		ratio =  0.06;
	window_max = ft_stacksize(holder->a) * ratio;
	while (ft_stacksize(holder->a) > 3 && !sort_finished(holder))
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
		{
			if (ft_stacklast(holder->a)->rank <= window_max)
				reverse_rotate(&(holder)->a, holder, 0);
			else
				rotate(&(holder)->a, holder, 0);
		}
	}
}

void	refill_a(t_holder *holder)
{
	int	biggest;

	while (ft_stacksize(holder->b))
	{
		biggest = biggest_elem(holder->b);
		fastest_path(&holder->b, ft_equals, holder, biggest);
		fastest_path(&holder->a, ft_equals, holder, biggest + 1);
		push(&holder->b, &holder->a, holder);
	}
}
