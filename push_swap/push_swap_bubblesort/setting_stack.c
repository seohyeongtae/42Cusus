/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:14:12 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/07 19:13:16 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*set_stack(int index, int factor)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		print_error();
	stack->next = NULL;
	stack->front = NULL;
	stack->num = factor;
	stack->index = 0;
	return (stack);
}

// +, - 는 중복 모두 체크하며 002 등은 인트로 계산  스페이스바도 체크해야 한다...........
int	change_factor(char *check)
{
	long long	factor;
	int			i;
	int			minus;

	i = -1;
	factor = 0;
	minus = 1;
	while (check[++i] && (check[i] == '+'
			|| check[i] == '-' || check[i] == ' '))
	{
		if (check[i] == '-')
			minus *= -1;
	}
	if (!('0' <= check[i] && check[i] <= '9'))
		print_error();
	while (check[i])
	{
		factor *= 10;
		factor += check[i] - '0';
		i++;
		while (check[i] == ' ')
			i++;
	}
	return (factor * minus);
}

char	check_factor(long long factor)
{
	if (factor < -2147483648 || factor > 2147483647)
		return (0);
	return ('1');
}

void	setting_stack(t_stack *temstack, char *argv, int i, t_stack *astack)
{
	long long	factor;

	if (!(factor = change_factor(argv)) && factor != 0)
		print_error();
	if (i == 1)
	{
		if ((!check_factor(factor)) || !make_firststack((int)factor, temstack))
			print_error();
		make_firststack((int)factor, astack);
	}
	else if ((!check_factor(factor)) || !make_temstack((int)factor, temstack) || !make_astack((int)factor, astack))
			print_error();
}
