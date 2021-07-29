/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:07:39 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 18:07:39 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	if (stack->front)
	{
		while (stack->front)
			stack = stack->front;
	}
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
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
