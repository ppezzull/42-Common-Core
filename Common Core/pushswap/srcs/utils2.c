#include "push_swap.h"

void	error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

int	is_sorted(t_program *program)
{
	t_stack	*tmp;

	tmp = program->a;
	while (tmp->next)
	{
		if (tmp->next->num < tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_repeated(t_program *program)
{
	int	*sorted;
	int	i;

	sorted = stack_into_sorted_lst(program->a);
	i = 0;
	while (sorted[i] && sorted[i + 1])
	{
		if (sorted[i] == sorted[i + 1])
			return (1);
		i++;
	}
	free(sorted);
	return (0);
}

void	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				error();
			j++;
		}
		i++;
	}
}