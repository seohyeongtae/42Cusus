/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:15:26 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 18:15:26 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*run_pa_min(t_stack *astack, t_stack *bstack)
{
	t_stack	*new_stack;

	new_stack = set_stack(0);
	new_stack->num = bstack->num;
	astack->front = new_stack;
	new_stack->next = astack;
	if (bstack->next)
		(bstack->next)->front = NULL;
	free(bstack);
	write(1, "pa\n", 3);
	return (new_stack);
}

t_stack	*run_reverse(t_stack *astack, int pivot)
{
	astack = run_ra(astack);
	pivot++;
	return (astack);
}

t_stack	*run_pb_min(t_stack *astack, t_stack *bstack)
{
	t_stack	*next_astack;
	int		count;

	count = 1;
	next_astack = astack->next;
	if (bstack->next)
		count = 2;
	if (count == 1 && bstack->index == 0)
	{
		bstack->num = astack->num;
		bstack->index = 1;
		free(astack);
	}
	else
	{
		astack->next = bstack;
		bstack->front = astack;
		astack->index = 1;
	}
	next_astack->front = NULL;
	write(1, "pb\n", 3);
	if (bstack->front)
		check_pp_b_min(next_astack, bstack);
	return (next_astack);
}
