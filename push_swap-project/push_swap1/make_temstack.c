/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_temstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:10:26 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/06 20:37:27 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// factor 가 더 큰 경우 temstack->num < factor
char	linked_temstack_back(int factor, t_stack *temstack)
{
	t_stack	*new_stack;

	new_stack = set_stack(1, factor);
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

// factor 가 더 작은 경우 temstack->num > factor
char	linked_temstack_front(int factor, t_stack *temstack)
{
	t_stack	*new_stack;

	new_stack = set_stack(1, factor);
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

// 중복 여부 확인해야 한다.
char	make_temstack(int factor, t_stack *temstack)
{
	// factor가 더 큰 경우 next 으로 가면서 봐야함
	if (temstack->num < factor)
		return (linked_temstack_back(factor, temstack));
	// factor 가 더 작을 경우 front로 진행
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

int	find_pivot_a(int argc, t_stack *temstack)
{
	int	pivot;
	int i;

	pivot = 0;
	i = 0;
	while (temstack->next)
		temstack = temstack->next;
	while (i++ < argc)
	{
		if (temstack->front)
			temstack = temstack->front;
	}
	pivot = temstack->num;
	return (pivot);
}

int	find_pivot(int argc, t_stack *temstack)
{
	int	pivot;
	int i;

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
