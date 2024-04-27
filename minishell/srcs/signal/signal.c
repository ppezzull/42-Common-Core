/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensteum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:52:02 by ensteum           #+#    #+#             */
/*   Updated: 2024/04/26 15:52:05 by ensteum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_ctrl_c(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}

void	handle_ctrl_d(int sig)
{
	(void)sig;
	exit(EXIT_SUCCESS);
}

void	handle_ctrl_backslash(int sig)
{
	(void)sig;
}
