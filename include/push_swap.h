#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ultralibft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}				t_stack;

t_stack	*ft_new_stack(int content);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);

#endif
