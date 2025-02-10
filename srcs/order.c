#include "push_swap.h"

int	three_ordered(t_stack *first)
{
	t_stack	*second;
	t_stack	*third;
	t_stack	*smallest;

	second = first->next;
	third = second->next;
	if ((first->rank < second->rank && first->rank < first->rank) && second->rank > third->rank)
		return (1);
	if (first->rank > second->rank && first->rank < third->rank)
		return (1);
	if (first->rank > second->rank && first->rank > third->rank)
		return (1);
	//dans ces trois scenarios il faut swap puis smallest at top
}
