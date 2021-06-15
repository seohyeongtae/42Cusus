/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:35:57 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/13 20:41:37 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*check;

	check = lst;
	count = 1;
	if (!lst)
		return (0);
	while (check->next)
	{
		check = check->next;
		count++;
	}
	return (count);
}
