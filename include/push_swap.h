#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ultralibft.h"
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}				t_stack;

t_stack		*ft_new_stack(int content);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stackclear(t_stack **stack);

long long	ft_atoll(char *nptr);
int			check_only_digits(char *str);
int			check_dups(char **arv, int index);
int			check_params(char **arv);

#endif
