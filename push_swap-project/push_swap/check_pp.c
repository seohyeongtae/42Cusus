/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:13:53 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 18:13:53 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*check_pp_b(t_stack *astack, t_stack *bstack, int pivot, int count)
{
	int	pa;
	int	rb;
	int	check;

	pa = 0;
	rb = 0;
	check = count;
	while (--count >= 0)
	{
		if ((bstack->num >= pivot && pa++ >= 0) || !(bstack->next))
			bstack = run_pa(astack, bstack);
		else if (bstack->next && rb++ >= 0)
			bstack = run_rb(bstack);
	}
	pivot = rb;
	while (bstack->next && rb-- > 0)
		bstack = run_rrb(bstack);
	while (astack->front)
		astack = astack->front;
	if (pa > 0 && check > 1)
		astack = check_pp(astack, bstack, pa);
	if (pivot > 0)
		bstack = check_b(astack, bstack, pivot);
	return (bstack);
}

t_stack	*check_b(t_stack *astack, t_stack *bstack, int count)
{
	int		pivot;
	int		pa;
	int		rb;
	t_stack	*b;
	t_stack	*b_tem;

	pa = 1;
	rb = count;
	b = bstack;
	b_tem = set_stack(0);
	while (rb > 0)
	{
		setting_stack_tem(b_tem, b->num, pa++);
		b = b->next;
		rb--;
	}
	pa = 0;
	pivot = find_pivot((count / 2) + (count % 2), b_tem);
	free_stack(b_tem);
	bstack = check_pp_b(astack, bstack, pivot, count);
	return (bstack);
}

t_stack	*check_pp_a_s(t_stack *astack, t_stack *bstack, int ra, int pb)
{
	int	tem_ra;

	tem_ra = ra;
	while (astack->next && ra-- > 0)
		astack = run_rra(astack);
	if (tem_ra > 1)
		astack = check_pp(astack, bstack, tem_ra);
	while (bstack->front)
		bstack = bstack->front;
	if (pb > 0)
		bstack = check_b(astack, bstack, pb);
	return (astack);
}

t_stack	*check_pp_a(t_stack *astack, t_stack *bstack, int pivot, int count)
{
	int	pb;
	int	ra;

	pb = 0;
	ra = 0;
	if (count > 1)
	{
		while (--count >= 0)
		{		
			if (astack->num < pivot && pb++ >= 0)
				astack = run_pb(astack, bstack);
			if (bstack->front)
				bstack = bstack->front;
			else if (astack->next && ra++ >= 0)
				astack = run_ra(astack);
		}
	}
	astack = check_pp_a_s(astack, bstack, ra, pb);
	return (astack);
}

t_stack	*check_pp(t_stack *astack, t_stack *bstack, int count)
{
	int		pivot;
	int		pb;
	int		ra;
	t_stack	*a;
	t_stack	*a_tem;

	pb = 1;
	a = astack;
	a_tem = set_stack(0);
	ra = count;
	while (ra > 0)
	{
		setting_stack_tem(a_tem, a->num, pb++);
		a = a->next;
		ra--;
	}
	pb = 0;
	pivot = find_pivot(count / 2, a_tem);
	free_stack(a_tem);
	astack = check_pp_a(astack, bstack, pivot, count);
	return (astack);
}
