#include "push_swap.h"

void	rank_list(t_stack	**stack)
{
	int		cmp;
	int		rank;
	t_stack	*tmp;
	int		size;
	t_stack	*change;

	size = ft_stacksize(*stack);
	//ft_printf(1, "size of stack is %d\n", size);
	rank = 1;
	while (rank <= size)
	{
		tmp = *stack;
		cmp = INT_MAX;
		while (tmp != NULL)
		{
			if (tmp->content <= cmp && !tmp->rank)
			{
				change = tmp;
				cmp = tmp->content;
			}
			tmp = tmp->next;
		}
		change->rank = rank;
		rank ++;
	}
}
