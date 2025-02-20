/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:35:06 by wivallee          #+#    #+#             */
/*   Updated: 2025/02/20 10:35:08 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack *stack)
{
	t_stack	*tmp;
	size_t	count;

	tmp = stack;
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

int	ft_equals(size_t testing_value, size_t reference)
{
	if (testing_value == reference)
		return (1);
	return (0);
}

void	refill_a(t_holder *holder)
{
	int	biggest;

	while (ft_stacksize(holder->b))
	{
		biggest = biggest_elem(holder->b);
		fastest_path(&holder->b, ft_equals, holder, biggest);
		fastest_path(&holder->a, ft_equals, holder, biggest + 1);
		push(&holder->b, &holder->a, holder, 0);
	}
}
