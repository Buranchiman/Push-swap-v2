#include "push_swap.h"

void	push(t_stack **from, t_stack **to, t_holder *holder)
{
	t_stack	*tmp;

	tmp = *from;
	*from = (*from)->next;
	tmp->next = NULL;
	ft_stackadd_front(to, tmp);
	if (*from == holder->a)
		ft_printf(1, "pb\n");
	else if (*from == holder->b)
		ft_printf(1, "pa\n");
}

void	rotate(t_stack	**stack, t_holder *holder)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stackadd_back(stack, tmp);
	if (*stack == holder->a)
		ft_printf(1, "ra\n");
	else if (*stack == holder->b)
		ft_printf(1, "rb\n");
}

void	reverse_rotate(t_stack	**stack, t_holder *holder)
{
	t_stack	*tmp;
	t_stack	*moved;

	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	moved = tmp->next;
	tmp->next = NULL;
	ft_stackadd_front(stack, moved);
	if (*stack == holder->a)
		ft_printf(1, "rra\n");
	else if (*stack == holder->b)
		ft_printf(1, "rrb\n");
}

void	swap(t_stack	**stack, t_holder *holder)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*stack)->next;
	tmp2 = tmp1->next;
	(*stack)->next = tmp2;
	tmp1->next = *stack;
	*stack = tmp1;
	if (*stack == holder->a)
		ft_printf(1, "sa\n");
	else if (*stack == holder->b)
		ft_printf(1, "sb\n");
}