#include "push_swap.h"

t_stack	*ft_new_stack(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->content = content;
	stack->rank = 0;
	stack->next = NULL;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (stack != NULL)
	{
		if (*stack != NULL)
		{
			temp = *stack;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
		else
			*stack = new;
	}
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*point;

	if (stack != NULL)
	{
		while (*stack != NULL)
		{
			point = (*stack)->next;
			free(*stack);
			*stack = point;
		}
	}
}

int	ft_stacksize(t_stack *stack)
{
	int		i;
	t_stack	*point;

	i = 0;
	point = stack;
	while (point != NULL)
	{
		point = point->next;
		i++;
	}
	return (i);
}