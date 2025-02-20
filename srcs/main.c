/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:34:05 by wivallee          #+#    #+#             */
/*   Updated: 2025/02/20 10:34:06 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	check_params(arv);
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
