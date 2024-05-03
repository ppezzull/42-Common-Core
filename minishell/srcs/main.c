/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:50:30 by ppezzull          #+#    #+#             */
/*   Updated: 2024/02/04 18:50:33 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char	*input;

	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, handle_ctrl_backslash);
	while (1)
	{
		input = readline(VIOLET "> ");
		if (input == NULL)
		{
			handle_ctrl_d(SIGQUIT);
			break ;
		}
		if (input && *input)
		{
			add_history(input);
		}
		free(input);
	}
	return (0);
}
