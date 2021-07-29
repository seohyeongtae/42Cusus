/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pp_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:20:00 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 18:20:00 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_sort_three(t_stack *astack, t_stack *next, t_stack *final)
{
	if (astack->num > next->num && astack->num > final->num
		&& next->num > final->num)
		return (1);
	else if (astack->num > next->num && astack->num > final->num
		&& next->num < final->num)
		return (2);
	else if (astack->num > next->num && astack->num < final->num
		&& next->num < final->num)
		return (3);
	else if (astack->num < next->num && astack->num > final->num
		&& next->num > final->num)
		return (4);
	else if (astack->num < next->num && astack->num < final->num
		&& next->num < final->num)
		return (5);
	else if (astack->num < next->num && astack->num < final->num
		&& next->num > final->num)
		return (6);
	return (0);
}

int	*check_pp_b_min(t_stack *astack, t_stack *bstack)
{
	t_stack	*bnext_stack;
	t_stack	*final_stack;

	while (bstack->front)
		bstack = bstack->front;
	bnext_stack = bstack->next;
	final_stack = bstack;
	while (final_stack->next)
		final_stack = final_stack->next;
	if (check_sort_b(bstack))
		return (0);
	else if (final_stack->num < bstack->num)
		bstack = run_rrb(bstack);
	else if (bstack->num < bnext_stack->num)
		bstack = run_sb(bstack);
	else if (bstack->num < bnext_stack->num)
		run_rb(bstack);
	else
		run_rrb(bstack);
	if (!check_sort_b(bstack))
		check_pp_b_min(astack, bstack);
	return (0);
}

t_stack	*pp_min_run(t_stack *astack, t_stack *f_stack, int pivot, int f_num)
{
	t_stack	*anext_stack;

	anext_stack = astack->next;
	 if (astack->num < f_stack->num && astack->num < anext_stack->num
		 && astack->num != pivot && astack->num != f_num)
	{
		astack = run_rra(astack);
		astack = run_sa(astack);
	}
	else if (astack->num < f_stack->num && astack->num < anext_stack->num
		&& astack->num != pivot && astack->num != f_num)
		run_sa(astack);
	else if (astack->num < f_stack->num && astack->num > anext_stack->num
		&& astack->num != pivot && astack->num != f_num)
	{
		astack = run_rra(astack);
		astack = run_sa(astack);
	}
	else
		astack = run_ra(astack);
	return (astack);
}

t_stack	*check_pp_min(t_stack *astack, t_stack *bstack, int pivot, int f_num)
{
	t_stack	*anext_stack;
	t_stack	*final_stack;

	anext_stack = astack->next;
	final_stack = astack;
	while (final_stack->next)
		final_stack = final_stack->next;
	if (astack->num < pivot)
		astack = run_pb_min(astack, bstack);
	else if (check_sort_re(astack))
		run_reverse(astack, pivot);
	else
		astack = pp_min_run(astack, final_stack, pivot, f_num);
	return (astack);
}
