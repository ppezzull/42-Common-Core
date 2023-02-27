#include "push_swap.h"

t_stack	*ft_new_stack(int nb)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = nb;
	stack->next = NULL;
	stack->previous = NULL;
	return (stack);
}

int	*get_lst(char *argv)
{
	int	*lst;
	int	i;
	int	len;

	
	i = -1;
	len = 0;
	while (argv[i++])
		if (ft_isnum(argv[i]))
			len++
	if (!lst)
		return (NULL);
	
	
}
