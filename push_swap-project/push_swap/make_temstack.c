/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_temstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:10:26 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 16:21:43 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	linked_temstack_back(int factor, t_stack *temstack)
{
	t_stack	*new_stack;

	new_stack = set_stack(factor);
	while (temstack)
	{
		if (temstack->next == NULL)
		{
			new_stack->front = temstack;
			temstack->next = new_stack;
			return ('1');
		}
		temstack = temstack->next;
		if (temstack->num == factor)
			print_error();
		if (temstack->num > factor)
		{
			new_stack->front = temstack->front;
			new_stack->next = (temstack->front)->next;
			(temstack->front)->next = new_stack;
			temstack->front = new_stack;
			return ('1');
		}
	}
	return (0);
}

char	linked_temstack_front(int factor, t_stack *temstack)
{
	t_stack	*new_stack;

	new_stack = set_stack(factor);
	while (temstack)
	{
		if (temstack->front == NULL)
		{
			new_stack->next = temstack;
			temstack->front = new_stack;
			return ('1');
		}
		temstack = temstack->front;
		if (temstack->num == factor)
			print_error();
		if (temstack->num < factor)
		{
			new_stack->next = temstack->next;
			new_stack->front = (temstack->next)->front;
			(temstack->next)->front = new_stack;
			temstack->next = new_stack;
			return ('1');
		}
	}
	return (0);
}

char	make_temstack(int factor, t_stack *temstack)
{
	if (temstack->num < factor)
		return (linked_temstack_back(factor, temstack));
	else if (temstack->num > factor)
		return (linked_temstack_front(factor, temstack));
	else
		print_error();
	return ('1');
}

char	make_firststack(int factor, t_stack *temstack)
{
	temstack->num = factor;
	return ('1');
}

int	find_pivot_min(int argc, t_stack *temstack)
{
	int	pivot;
	int	i;

	pivot = 0;
	i = 0;
	while (temstack->front)
		temstack = temstack->front;
	while (++i < argc / 2)
	{
		if (temstack->next)
			temstack = temstack->next;
	}
	pivot = temstack->num;
	return (pivot);
}

int	find_pivot(int argc, t_stack *temstack)
{
	int	pivot;
	int	i;

	pivot = 0;
	i = 0;
	while (temstack->front)
		temstack = temstack->front;
	while (i++ < argc)
	{
		if (temstack->next)
			temstack = temstack->next;
	}
	pivot = temstack->num;
	return (pivot);
}
