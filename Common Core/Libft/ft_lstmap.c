/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:25:34 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/30 20:25:38 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy_head;
	t_list	*lst_copy;
    int     is_head;

	if (!lst || !f || !del)
		return (NULL);
    is_head = 1;
    while (lst)
	{
		lst_copy = ft_lstnew(f(lst->content));
		if (!lst_copy)
        {
			if (is_head == 1)
                ft_lstclear(&lst_copy, del);
            else
                ft_lstclear(&copy_head, del);
            return (0);
        }
        if (is_head == 1)
            copy_head = lst_copy;
		lst_copy = lst_copy->next,
		lst = lst->next;
        is_head = 0;
	}
	return (lst_copy);
}
