/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:52:44 by dshushku          #+#    #+#             */
/*   Updated: 2022/10/23 19:16:53 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	fill(int tab[4][4]);

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		*get_numbers(char *str);
int		check(int ac, char **av);
int		check_double(int tab[4][4], int pos, int num);
int		check_case(int tab[4][4], int pos, int entry[16]);

int	solve(int tab[4][4], int entry[16], int pos)
{
	int	size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (check_double(tab, pos, size) == 0)
		{
			tab[pos / 4][pos % 4] = size;
			if (check_case(tab, pos, entry) == 0)
			{
				if (solve(tab, entry, pos + 1) == 1)
					return (1);
			}
			else
				tab[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}

void	display_solution(int tab[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(tab[i][j]);
			if (j < 3)
			{
				ft_putchar(' ');
			}
		}
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int	tab[4][4];
	int	*entry;

	fill(tab);
	if (check(ac, av) == 1)
		return (0);
	entry = get_numbers(av[1]);
	if (solve(tab, entry, 0) == 1)
		display_solution(tab);
	else
		ft_putstr("Did not find any solutions\n");
	return (0);
}
