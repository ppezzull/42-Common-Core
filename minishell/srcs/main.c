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

	// Install signal handlers
	signal(SIGINT, handle_ctrl_c);          // Ctrl-C
	signal(SIGQUIT, handle_ctrl_backslash); // Ctrl-
	while (1)
	{
		// Read input using readline
		input = readline(VIOLET "> " RESET_COLOR);
		if (input == NULL)
		{                           // Ctrl-D (EOF) pressed
			handle_ctrl_d(SIGQUIT); // Update function call
			break ;                  // Exit the loop
		}
		// Add input to history
		if (input && *input)
		{
			add_history(input);
		}
		// Tokenize input (Parser)
		// Execute commands (Executor)
		// Handle built-in commands and external commands
		// Free input memory
		free(input);
	}
	return (0);
}
