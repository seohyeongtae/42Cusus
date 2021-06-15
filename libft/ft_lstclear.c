/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:40:38 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/13 22:17:48 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*result;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		result = (*(*lst)).next;
		del((*lst)->content);
		free((*lst));
		*lst = result;
	}
	free((*lst));
}
