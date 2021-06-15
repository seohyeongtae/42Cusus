/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:31:05 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/21 16:44:23 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*c;
	t_list	*new;
	t_list	*result;

	if (!lst || !f)
		return (0);
	if (!(result = ft_lstnew(f(lst->content))))
		return (0);
	new = result;
	lst = lst->next;
	while (lst)
	{
		if (!(c = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&result, del);
			return (0);
		}
		new->next = c;
		new = c;
		lst = lst->next;
	}
	return (result);
}
