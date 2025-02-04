#include "push_swap.h"

void	push(t_stack **from, t_stack **to, t_holder *holder)
{
	t_stack	*tmp;

	tmp = *from;
	*from = (*from)->next;
	tmp->next = NULL;
	ft_stackadd_front(to, tmp);
	if (to == &(holder)->a)
		ft_printf(1, "%s", "pa\n");
	else
		ft_printf(1, "%s", "pb\n");
}

void	rotate(t_stack	**stack, t_holder *holder, int option)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stackadd_back(stack, tmp);
	if (option == 0)
	{
		if (*stack == holder->a)
			ft_printf(1, "ra\n");
		else
			ft_printf(1, "rb\n");
	}
	if (option == 1)
		return ;
	if (option == 2)
		ft_printf(1, "rr\n");
}

void	reverse_rotate(t_stack	**stack, t_holder *holder, int option)
{
	t_stack	*tmp;
	t_stack	*moved;

	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	moved = tmp->next;
	tmp->next = NULL;
	ft_stackadd_front(stack, moved);
	if (option == 0)
	{
		if (*stack == holder->a)
			ft_printf(1, "rra\n");
		else
			ft_printf(1, "rrb\n");
	}
	if (option == 1)
		return ;
	if (option == 2)
		ft_printf(1, "rrr\n");
}

void	swap(t_stack	**stack, t_holder *holder, int option)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*stack)->next;
	tmp2 = tmp1->next;
	(*stack)->next = tmp2;
	tmp1->next = *stack;
	*stack = tmp1;
	if (option == 0)
	{
		if (*stack == holder->a)
			ft_printf(1, "sa\n");
		else
			ft_printf(1, "sb\n");
	}
	if (option == 1)
		return ;
	if (option == 2)
		ft_printf(1, "ss\n");
}
