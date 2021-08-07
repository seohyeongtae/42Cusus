/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:07:39 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 18:07:39 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flag(char *check)
{
	int	i;
	int	minus;
	int	plus;

	i = -1;
	minus = 1;
	plus = 0;
	while (check[++i] && (check[i] == '+'
			|| check[i] == '-' || check[i] == ' '))
	{	
		if (check[i] == '-')
		{
			if (plus == 1 || minus == -1)
				print_error();
			minus = -1;
		}
		if (check[i] == '+')
		{
			if (plus == 1 || minus == -1)
				print_error();
			plus = 1;
		}
	}
	return (minus);
}

char	check_sort_b(t_stack *bstack)
{
	while (bstack->front)
		bstack = bstack->front;
	while (bstack->next)
	{
		if (bstack->num < (bstack->next)->num)
			return (0);
		bstack = bstack->next;
	}
	return ('1');
}

char	check_sort_re(t_stack *astack)
{
	while (astack->front)
		astack = astack->front;
	while (astack->next)
	{
		if (astack->num < (astack->next)->num)
			return (0);
		astack = astack->next;
	}
	return ('1');
}

int	simple_check_sort(t_stack *astack)
{
	if (astack->next)
	{
		if (astack->num < (astack->next)->num)
			return (0);
		else
			run_ra(astack);
	}
	return (0);
}

char	check_sort(t_stack *astack, t_stack *bstack)
{
	while (astack->front)
		astack = astack->front;
	while (bstack->front)
		bstack = bstack->front;
	if (astack->num < bstack->num)
		return (0);
	while (astack->next)
	{
		if (astack->num > (astack->next)->num)
			return (0);
		astack = astack->next;
	}
	while (bstack->next)
	{
		if (bstack->num < (bstack->next)->num)
			return (0);
		bstack = bstack->next;
	}
	return ('1');
}
