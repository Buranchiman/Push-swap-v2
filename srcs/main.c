#include "push_swap.h"

void	print_list(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf(1, "content of stack is %d and rank is %d\n", tmp->content, tmp->rank);
		tmp = tmp->next;
	}
}

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
	// print_list(holder.a);
	// push(&(holder).a, &(holder).b, "pb\n");
	// print_list(holder.a);
	// //ft_printf(1, "content of b is :\n");
	// print_list(holder.b);
	// rotate(&(holder).a, "ra\n");
	// print_list(holder.a);
	sortstack(&holder);
	print_list(holder.b);
	ft_printf(1, "stack a is :\n");
	print_list(holder.a);
	return (0);
}