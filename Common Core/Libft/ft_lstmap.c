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
	t_list	*tmp;
	t_list	*lst_copy;

	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(lst->content);
		if (!tmp)
			ft_lstdelone(tmp, del);
		ft_lstadd_back(&lst_copy, tmp);
		lst = lst->next;
	}
	return (lst_copy);
}
