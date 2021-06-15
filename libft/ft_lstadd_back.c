/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:45:37 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/13 21:17:53 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*result;

	result = *lst;
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (result->next)
	{
		result = result->next;
	}
	result->next = new;
}
