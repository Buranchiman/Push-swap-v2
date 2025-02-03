#include "push_swap.h"

void	push(t_stack **from, t_stack **to, char *msg)
{
	t_stack	*tmp;

	tmp = *from;
	*from = (*from)->next;
	tmp->next = NULL;
	ft_stackadd_front(to, tmp);
	if (msg)
		ft_printf(1, "%s", msg);
}

void	rotate(t_stack	**stack, char	*msg)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stackadd_back(stack, tmp);
	if (msg)
		ft_printf(1, "%s", msg);
}

void	reverse_rotate(t_stack	**stack, char *msg)
{
	t_stack	*tmp;
	t_stack	*moved;

	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	moved = tmp->next;
	tmp->next = NULL;
	ft_stackadd_front(stack, moved);
	if (msg)
		ft_printf(1, "%s", msg);
}

void	swap(t_stack	**stack, char *msg)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*stack)->next;
	tmp2 = tmp1->next;
	(*stack)->next = tmp2;
	tmp1->next = *stack;
	*stack = tmp1;
	if (msg)
		ft_printf(1, "%s", msg);
}