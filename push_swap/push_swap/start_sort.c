/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:17:23 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 18:17:23 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*end_sort(t_stack *astack, t_stack *bstack)
{
	t_stack	*temp;

	if (bstack->index == 0 && !(bstack->next))
		return (astack);
	temp = bstack;
	while (temp)
	{
		temp = temp->next;
		astack = run_pa_min(astack, bstack);
		bstack = temp;
	}
	return (astack);
}

t_stack	*simple_check_sort_three(t_stack *astack)
{
	t_stack	*final;
	t_stack	*next;
	int		num;

	final = (astack->next)->next;
	next = astack->next;
	num = num_sort_three(astack, next, final);
	if (num == 1)
	{
		astack = run_sa(astack);
		astack = run_rra(astack);
	}
	else if (num == 2)
		astack = run_ra(astack);
	else if (num == 3)
		astack = run_sa(astack);
	else if (num == 4)
		astack = run_rra(astack);
	else if (num == 6)
	{
		astack = run_rra(astack);
		astack = run_sa(astack);
	}
	return (astack);
}

t_stack	*start_sort_min(t_stack *astack, t_stack *bstack, t_stack *tem, int a)
{
	int	f_num;
	int	pivot;

	pivot = find_pivot_min(a, tem);
	while (astack->front)
		astack = astack->front;
	while (bstack->front)
		bstack = bstack->front;
	while (tem->next)
		tem = tem->next;
	f_num = tem->num;
	if (!check_sort(astack, bstack))
	{
		astack = check_pp_min(astack, bstack, pivot, f_num);
		start_sort_min(astack, bstack, tem, a);
	}
	else
	{
		astack = end_sort(astack, bstack);
		return (astack);
	}
	return (astack);
}

t_stack	*simple_check_sort_five(t_stack *astack, t_stack *b, t_stack *t, int a)
{
	int	pivot;
	int	count;

	count = 0;
	pivot = find_pivot_min(a, t);
	while (count < 5)
	{
		if (astack->num < pivot)
			astack = run_pb_min(astack, b);
		else
			astack = run_ra(astack);
		astack = astack->next;
		while (astack->front)
			astack = astack->front;
		count++;
	}
	astack = simple_check_sort_three(astack);
	if (b->front)
		b = b->front;
	if (b->num < (b->next)->num)
		b = run_sb(b);
	astack = run_pa_min(astack, b);
	b = b->next;
	astack = run_pa_min(astack, b);
	return (astack);
}

t_stack	*start_sort(t_stack *astack, int count, t_stack *tem)
{
	int		pivot;
	int		i;
	t_stack	*bstack;

	bstack = set_stack(0);
	i = 0;
	pivot = find_pivot(count / 2, tem);
	if (!(check_sort(astack, bstack)))
	{
		while (i++ < count)
		{
			if (astack->num < pivot)
			{
				astack = run_pb(astack, bstack);
				if (bstack->front)
					bstack = bstack->front;
			}
			else
				astack = run_ra(astack);
		}		
		astack = check_pp(astack, bstack, (count / 2) + (count % 2));
		if (!check_sort_b(bstack))
			 bstack = check_b(astack, bstack, (count / 2));
	}
	return (astack);
}
