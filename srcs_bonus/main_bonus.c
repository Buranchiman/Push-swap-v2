/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:38:28 by wivallee          #+#    #+#             */
/*   Updated: 2025/02/20 16:33:26 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	read_pushswap(char *instruction, t_holder *holder)
{
	if (!ft_strncmp(instruction, "sa\n", 4))
		swap(&(holder)->a, holder, 1);
	else if (!ft_strncmp(instruction, "sb\n", 4))
		swap(&(holder)->b, holder, 1);
	else if (!ft_strncmp(instruction, "ss\n", 4))
	{
		swap(&(holder)->a, holder, 1);
		swap(&(holder)->b, holder, 1);
	}
	else if (!ft_strncmp(instruction, "pa\n", 4))
		push(&(holder)->b, &(holder)->a, holder, 1);
	else if (!ft_strncmp(instruction, "pb\n", 4))
		push(&(holder)->a, &(holder)->b, holder, 1);
	else
		return (-1);
	return (0);
}

int	read_rotate(char *instruction, t_holder *holder)
{
	if (!ft_strncmp(instruction, "ra\n", 4))
		rotate(&(holder)->a, holder, 1);
	else if (!ft_strncmp(instruction, "rb\n", 4))
		rotate(&(holder)->b, holder, 1);
	else if (!ft_strncmp(instruction, "rr\n", 4))
	{
		rotate(&(holder)->a, holder, 1);
		rotate(&(holder)->b, holder, 1);
	}
	else if (!ft_strncmp(instruction, "rra\n", 5))
		reverse_rotate(&(holder)->a, holder, 1);
	else if (!ft_strncmp(instruction, "rrb\n", 5))
		reverse_rotate(&(holder)->b, holder, 1);
	else if (!ft_strncmp(instruction, "rrr\n", 5))
	{
		reverse_rotate(&(holder)->a, holder, 1);
		reverse_rotate(&(holder)->b, holder, 1);
	}
	else
		return (-1);
	return (0);
}

void	read_instructions(t_holder *holder)
{
	char	*tmp;

	tmp = get_next_line(1);
	while (tmp)
	{
		if (read_pushswap(tmp, holder) == -1 && read_rotate(tmp, holder) == -1)
		{
			free(tmp);
			ft_stackclear(&(holder->a));
			ft_stackclear(&(holder->b));
			ft_printf(2, "Error\n");
			exit (EXIT_FAILURE);
		}
		free(tmp);
		tmp = get_next_line(1);
	}
}

int	main(int arc, char **arv)
{
	t_holder	holder;
	// int			i;

	if (arc == 1)
		return (1);
	// i = 1;
	holder.a = NULL;
	holder.b = NULL;
	get_numbers(arv, arc, &holder);
	// while (arv[i])
	// {
	// 	ft_stackadd_back(&(holder).a, ft_new_stack(ft_atoi(arv[i])));
	// 	i++;
	// }
	rank_list(&(holder).a);
	read_instructions(&holder);
	if (ft_sorted(holder.a) && !ft_stacksize(holder.b))
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	ft_stackclear(&holder.a);
	if (ft_stacksize(holder.b))
		ft_stackclear(&holder.b);
	return (0);
}
