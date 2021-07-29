/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:23:44 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 16:11:30 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	make_astack(int factor, t_stack *astack)
{
	t_stack	*new_stack;

	new_stack = set_stack(factor);
	while (astack->next)
		astack = astack->next;
	astack->next = new_stack;
	new_stack->front = astack;
	return ('1');
}

char	**make_argv(char **argv)
{
	char	*num;
	int		count;
	char	**final_num;

	num = (char *)malloc(sizeof(char) * 2);
	num[0] = ' ';
	num[1] = '\0';
	count = 1;
	while (argv[count])
	{
		num = ft_strjoin(num, argv[count]);
		num = ft_strjoin(num, " ");
		count++;
	}
	final_num = ft_split(num, ' ');
	free(num);
	return (final_num);
}

int	num_len(char **num)
{
	int	count;

	count = 0;
	while (*(num + count))
		count++;
	return (count);
}

int	main(int argc, char *argv[])
{
	t_stack		*temstack;
	int			check;
	t_stack		*astack;
	t_stack		*bstack;
	char		**num;

	check = -1;
	temstack = set_stack(0);
	astack = set_stack(0);
	bstack = set_stack(0);
	num = make_argv(argv);
	argc = num_len(num) + 1;
	while (*(num + ++check))
		setting_stack(temstack, *(num + check), check, astack);
	if (argc <= 3)
		simple_check_sort(astack);
	else if (argc == 4)
		astack = simple_check_sort_three(astack);
	else if (argc == 6)
		astack = simple_check_sort_five(astack, bstack, temstack, argc);
	else if (argc > 3 && argc < 12)
		start_sort_min(astack, bstack, temstack, argc);
	else
		astack = start_sort(astack, argc - 1, temstack);
	free_stack(temstack);
	free_stack(astack);
	free(num);
	//  system("leaks push_swap");
	return (0);
}
