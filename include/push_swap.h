/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:39:21 by wivallee          #+#    #+#             */
/*   Updated: 2025/02/20 10:40:28 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ultralibft.h"
# include <limits.h>

typedef struct s_stack
{
	int				content;
	size_t			rank;
	bool			is_initialized;
	struct s_stack	*next;
}				t_stack;

typedef struct s_holder
{
	t_stack	*a;
	t_stack	*b;
	size_t	window_min;
	size_t	window_max;
}				t_holder;

# define SMALL_LIST_RATIO 0.1f
# define BIG_LIST_RATIO 0.06f

t_stack		*ft_new_stack(int content);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stackclear(t_stack **stack);
int			ft_stacksize(t_stack *stack);

long long	ft_atoll(char *nptr);
int			check_only_digits(char *str);
int			check_dups(char **arv, int index);
int			check_params(char **arv);

void		push(t_stack **from, t_stack **to, t_holder *holder, int option);
void		rotate(t_stack	**stack, t_holder *holder, int option);
void		reverse_rotate(t_stack	**stack, t_holder *holder, int option);
void		swap(t_stack	**stack, t_holder *holder, int option);

void		rank_list(t_stack	**stack);

void		init_window(t_holder *holder);
void		in_window_or_smaller(t_holder *holder);
void		window_sort(t_holder *holder);

int			ft_sorted(t_stack *stack);
int			ft_equals(size_t testing_value, size_t reference);
void		refill_a(t_holder *holder);

void		fastest_path(t_stack **stack, int f(size_t elem, size_t cmp),
				t_holder *holder, int cmp);

t_stack		*ft_stacklast(t_stack *stack);
size_t		smallest_elem(t_stack *stack);
size_t		biggest_elem(t_stack	*stack);

void		three_ordered(t_holder *holder);
void		sort_small(t_holder *holder);

#endif
