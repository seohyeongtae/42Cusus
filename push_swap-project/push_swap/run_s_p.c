/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_s_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:12:44 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 18:12:44 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack	*run_pa(t_stack *astack, t_stack *bstack)
{
	t_stack	*next_stack;
	t_stack	*new_stack;

	next_stack = bstack;
	while (astack->front)
		astack = astack->front;
	if (!(bstack->next))
	{
		new_stack = set_stack(0);
		new_stack->num = bstack->num;
		astack->front = new_stack;
		new_stack->next = astack;
		free(bstack);
		write(1, "pa\n", 3);
		return (bstack);
	}
	if (bstack->next)
	{
		next_stack = bstack->next;
		next_stack->front = NULL;
		astack->front = bstack;
		bstack->next = astack;
		write(1, "pa\n", 3);
	}	
	return (next_stack);
}

t_stack	*run_pb(t_stack *astack, t_stack *bstack)
{
	t_stack	*next_astack;

	next_astack = astack;
	if (astack->next)
	{
		next_astack = astack->next;
		next_astack->front = NULL;
	}
	if (!(bstack->next) && bstack->index == 0)
	{
		bstack->num = astack->num;
		bstack->index = 1;
		bstack->next = NULL;
		free(astack);
	}
	else
	{
		astack->next = bstack;
		bstack->front = astack;
		astack->index = 1;
		astack->front = NULL;
	}
	write(1, "pb\n", 3);
	return (next_astack);
}

t_stack	*run_sb(t_stack *bstack)
{
	t_stack	*next_stack;
	t_stack	*third_stack;
	t_stack	*temp;

	next_stack = bstack->next;
	temp = NULL;
	if (next_stack->next)
		temp = next_stack->next;
	next_stack->front = NULL;
	next_stack->next = bstack;
	bstack->front = next_stack;
	if (temp)
	{
		third_stack = temp;
		bstack->next = third_stack;
		third_stack->front = bstack;
	}
	else
		bstack->next = NULL;
	write(1, "sb\n", 3);
	return (next_stack);
}

t_stack	*run_sa(t_stack *astack)
{
	t_stack	*next_stack;
	t_stack	*third_stack;
	t_stack	*temp;

	next_stack = astack->next;
	temp = NULL;
	if (next_stack->next)
		temp = next_stack->next;
	next_stack->front = NULL;
	next_stack->next = astack;
	astack->front = next_stack;
	if (temp)
	{
		third_stack = temp;
		astack->next = third_stack;
		third_stack->front = astack;
	}
	else
		astack->next = NULL;
	write(1, "sa\n", 3);
	return (next_stack);
}
