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
	t_list	*head;

	if (!lst)
		return ;
	ptr = lst;
	head = lst;
	while (lst->next)
	{
		(*f)(ptr->content);
		lst = lst->next;
		free(ptr);
		ptr = lst;
	}
	head = NULL;
}
