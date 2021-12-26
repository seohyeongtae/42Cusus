/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:12:24 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 18:33:15 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*run_rb(t_stack *bstack)
{
	t_stack	*final_stack;
	t_stack	*next_stack;

	next_stack = bstack->next;
	final_stack = bstack;
	while (final_stack->next)
		final_stack = final_stack->next;
	bstack->front = final_stack;
	bstack->next = NULL;
	final_stack->next = bstack;
	next_stack->front = NULL;
	write(1, "rb\n", 3);
	return (next_stack);
}

t_stack	*run_rrb(t_stack *bstack)
{
	t_stack	*final_stack;
	t_stack	*fi_front_stack;
	t_stack	*second_stack;

	final_stack = bstack;
	second_stack = bstack->next;
	while (final_stack->next)
		final_stack = final_stack->next;
	fi_front_stack = final_stack->front;
	if (second_stack->next)
	{
		fi_front_stack = final_stack->front;
		fi_front_stack->next = NULL;
	}
	else
		bstack->next = NULL;
	final_stack->front = NULL;
	final_stack->next = bstack;
	bstack->front = final_stack;
	write(1, "rrb\n", 4);
	return (final_stack);
}

t_stack	*run_ra(t_stack *astack)
{
	t_stack	*final_stack;
	t_stack	*next_stack;

	next_stack = astack->next;
	final_stack = astack;
	while (final_stack->next)
		final_stack = final_stack->next;
	astack->front = final_stack;
	astack->next = NULL;
	final_stack->next = astack;
	next_stack->front = NULL;
	write(1, "ra\n", 3);
	return (next_stack);
}

t_stack	*run_rra(t_stack *astack)
{
	t_stack	*final_stack;
	t_stack	*fi_front_stack;
	t_stack	*second_stack;

	final_stack = astack;
	second_stack = astack->next;
	while (final_stack->next)
		final_stack = final_stack->next;
	if (second_stack->next)
	{
		fi_front_stack = final_stack->front;
		fi_front_stack->next = NULL;
	}
	else
		astack->next = NULL;
	final_stack->front = NULL;
	final_stack->next = astack;
	astack->front = final_stack;
	write(1, "rra\n", 4);
	return (final_stack);
}
