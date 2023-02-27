/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:15:44 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/17 21:15:45 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <signal.h>
# include <sys/types.h>



typedef struct s_stack
{
	int				num;
	s_stack			*next;
	s_stack			*previous;
}					t_stack;

typedef struct s_program
{
	t_stack			*a;
	t_stack			*b;
}					t_program;

#endif
