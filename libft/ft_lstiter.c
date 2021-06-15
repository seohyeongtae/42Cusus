/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:20:46 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/14 14:23:30 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *re;

	if (!lst || !f)
		return ;
	re = lst;
	while (re)
	{
		f(re->content);
		re = re->next;
	}
}
