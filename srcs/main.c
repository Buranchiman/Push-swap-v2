#include "push_swap.h"

int	check_params(char **arv)
{
	int	i;

	i = 1;
	while (arv[i])
	{
		
	}
}

void	print_list(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf(1, "content of stack is %d\n", tmp->content);
		tmp = tmp->next;
	}
}

int	main(int arc, char **arv)
{
	t_stack	*a;
	int		i;

	if (arc == 1)
		return (1);
	i = 1;
	a = NULL;
	if (!check_params(arv))
		rerutnr(1);
	while (arv[i])
	{
		ft_stackadd_back(&a, ft_new_stack(ft_atoi(arv[i])));
		i++;
	}
	print_list(a);
	return (0);
}