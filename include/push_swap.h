#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ultralibft.h"
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				rank;
	struct s_stack	*next;
}				t_stack;

typedef struct s_holder
{
	t_stack	*a;
	t_stack	*b;
}				t_holder;

t_stack		*ft_new_stack(int content);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stackclear(t_stack **stack);
int			ft_stacksize(t_stack *stack);

long long	ft_atoll(char *nptr);
int			check_only_digits(char *str);
int			check_dups(char **arv, int index);
int			check_params(char **arv);

void		push(t_stack **from, t_stack **to, t_holder *holder);
void		rotate(t_stack	**stack, t_holder *holder, int option);
void		reverse_rotate(t_stack	**stack, t_holder *holder, int option);
void		swap(t_stack	**stack, t_holder *holder, int option);

void		rank_list(t_stack	**stack);

int			ft_equals(int testing_value, int reference);
int			ft_smaller(int i, int max);
void		sortstack(t_holder *holder);
void		refill_a(t_holder *holder);

int			fastest_path(t_stack **stack, int f(int elem, int cmp), t_holder *holder, int cmp);

int			smallest_elem(t_stack *stack);
int			biggest_elem(t_stack	*stack);
void		three_ordered(t_holder *holder);

#endif
