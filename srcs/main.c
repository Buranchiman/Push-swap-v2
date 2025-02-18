#include "push_swap.h"

int	main(int arc, char **arv)
{
	t_holder	holder;
	int			i;

	if (arc == 1)
		return (1);
	i = 1;
	holder.a = NULL;
	holder.b = NULL;
	if (!check_params(arv))
	{
		ft_printf(2, "Error\n");
		return (1);
	}
	while (arv[i])
	{
		ft_stackadd_back(&(holder).a, ft_new_stack(ft_atoi(arv[i])));
		i++;
	}
	rank_list(&(holder).a);
	window_sort(&holder);
	sort_small(&holder);
	refill_a(&holder);
	ft_stackclear(&(holder).a);
	return (0);
}
