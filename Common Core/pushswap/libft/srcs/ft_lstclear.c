/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:29:42 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/26 19:29:44 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*ptr_del;

	if (!lst || !del)
		return ;
	ptr = *lst;
	ptr_del = *lst;
	while (ptr)
	{
		ptr_del = ptr_del->next;
		(*del)(ptr->content);
		free(ptr);
		ptr = ptr_del;
	}
	*lst = NULL;
}
