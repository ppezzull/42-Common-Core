/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:19:44 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/20 17:19:46 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

char	bin_to_char(char *bin);
void	signal_handler(int signum);
void	send_message(char *message, int pid);
void	send_endl(int pid);
void	error(char *reason);

#endif