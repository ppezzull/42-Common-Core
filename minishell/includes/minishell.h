/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:49:36 by ppezzull          #+#    #+#             */
/*   Updated: 2024/02/04 18:49:49 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INPUT_LENGTH 1024
# define VIOLET "\033[35m"

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
}						t_env_node;

typedef struct s_minishell
{
	t_env_node			*head;
	char				*cwd;

}						t_minishell;


void					handle_ctrl_c(int sig);
void					handle_ctrl_d(int sig);
void					handle_ctrl_backslash(int sig);

#endif
