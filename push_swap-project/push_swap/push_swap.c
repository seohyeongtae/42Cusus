/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:23:44 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/28 22:02:53 by hyseo            ###   ########.fr       */
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
	t_stack *temp;
	
	if (stack->front)
	{
		while(stack->front)
			stack = stack->front;
	}
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

char	make_astack(int factor, t_stack *astack)
{
	t_stack *new_stack;

	if (!(new_stack = set_stack(factor)))
		return (0);
	while (astack->next)
		astack = astack->next;
	astack->next = new_stack;
	new_stack->front = astack;
	return ('1');
}

char	check_sort(t_stack *astack, t_stack *bstack)
{
	while (astack->front)
		astack = astack->front;
	while (bstack->front)
		bstack = bstack->front;
	if (astack->num < bstack->num)
		return (0);
	while (astack->next)
	{
		if (astack->num > (astack->next)->num)
			return (0);
		astack = astack->next;
	}
	while (bstack->next)
	{
		if (bstack->num < (bstack->next)->num)
			return (0);
		bstack = bstack->next;
	}
	return ('1');
}

char	check_sort_b(t_stack *bstack)
{
	while (bstack->front)
		bstack = bstack->front;
	while (bstack->next)
	{
		if (bstack->num < (bstack->next)->num)
			return (0);
		bstack = bstack->next;
	}
	return ('1');
}

t_stack	*run_pa(t_stack *astack, t_stack *bstack)
{
	t_stack	*next_stack;
	t_stack *new_stack;

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
		write(1, "pa\n",3);
		return (bstack);
	}
	if (bstack->next) 
	{
		next_stack = bstack->next;
		next_stack->front = NULL;
		astack->front = bstack;
		bstack->next = astack;
		bstack->front = NULL;
		write(1, "pa\n", 3);
		return (next_stack);
	}
	
	return (next_stack);
}

t_stack	*run_pb(t_stack *astack, t_stack *bstack)
{
	t_stack *next_astack;

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

t_stack	*run_rb(t_stack *bstack)
{
	t_stack *final_stack;
	t_stack *next_stack;

	next_stack = bstack->next;
	final_stack = bstack;
	while (final_stack->next)
		final_stack = final_stack->next;
	bstack->front = final_stack;
	bstack->next = NULL;
	final_stack->next = bstack;
	next_stack->front = NULL;
	write(1, "rb\n", 3);
	return(next_stack);
}

t_stack	*run_sb(t_stack *bstack)
{
	t_stack *next_stack;
	t_stack *third_stack;
	t_stack *temp;

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

t_stack	*run_rrb(t_stack *bstack)
{
	t_stack	*final_stack;
	t_stack *fi_front_stack;
	t_stack *second_stack;

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

t_stack *check_pp_b(t_stack *astack, t_stack *bstack, int pivot, int count)
{
	int	pa;
	int	rb;
	int	check;

	pa = 0;
	rb = 0;
	check = count;
	while (--count >= 0)
	{
		if (bstack->num >= pivot && pa++ >= 0)
			bstack = run_pa(astack, bstack);
		else if (bstack->next && rb++ >= 0)
			bstack = run_rb(bstack);
		else
			bstack = run_pa(astack, bstack);
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


t_stack *check_b(t_stack *astack, t_stack *bstack, int count)
{
	int	pivot;
	int	pa;
	int	rb;
	t_stack	*b;
	t_stack *b_tem;

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


t_stack	*run_ra(t_stack *astack)
{
	t_stack *final_stack;
	t_stack *next_stack;

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

t_stack	*run_sa(t_stack *astack)
{
	t_stack *next_stack;
	t_stack *third_stack;
	t_stack *temp;

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

t_stack	*run_rra(t_stack *astack)
{
	t_stack	*final_stack;
	t_stack *fi_front_stack;
	t_stack *second_stack;

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

t_stack *check_pp_a(t_stack *astack, t_stack *bstack, int pivot, int count)
{
	int ab;
	int pb;
	int ra;

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
	ab = ra;
	while (astack->next && ra-- > 0)
		astack = run_rra(astack);
	if (ab > 1)
		astack = check_pp(astack, bstack, ab);
	while (bstack->front)
			bstack = bstack->front;
	if (pb > 0)
		bstack = check_b(astack, bstack, pb);
	return (astack);
}

t_stack	*check_pp(t_stack *astack, t_stack *bstack, int count)
{
	int	pivot;
	int	pb;
	int	ra;
	t_stack	*a;
	t_stack *a_tem;

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

t_stack	*run_pa_min(t_stack *astack, t_stack *bstack)
{
	t_stack *new_stack;

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

char	check_sort_re(t_stack *astack)
{
	while (astack->front)
		astack = astack->front;
	while (astack->next)
	{
	if (astack->num < (astack->next)->num)
		return (0);
		astack = astack->next;
	}
		return ('1');
}

t_stack *run_reverse(t_stack *astack, int pivot)
{
	astack = run_ra(astack);
	pivot++;
	return (astack);
}

t_stack *end_sort(t_stack *astack, t_stack *bstack)
{
	t_stack	*temp;
	
	if (bstack->index == 0 && !(bstack->next))
		return (astack);
	temp = bstack;
	while (temp)
	{
			temp = temp->next;
			astack = run_pa_min(astack, bstack);
			bstack = temp;
	}
	return (astack);
}

t_stack	*start_sort(t_stack *astack, int count, t_stack *tem)
{
	int		pivot;
	int		i;
	t_stack *bstack;

	bstack = set_stack(0);
	i = 0;
	pivot = find_pivot(count / 2, tem);
	if (!(check_sort(astack, bstack)))
	{

		while (i++ < count)
		{
			if (astack->num < pivot)
			{
				astack = run_pb(astack, bstack);
				if (bstack->front)
					bstack = bstack->front;
			}
			else
				astack = run_ra(astack);
		}		
		astack = check_pp(astack, bstack, (count / 2) + (count % 2));
		if (!check_sort_b(bstack))
			 bstack = check_b(astack, bstack, (count / 2));
	}
	return (astack);
}

int		num_sort_three(t_stack *astack, t_stack *next, t_stack *final)

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

t_stack		*simple_check_sort_three(t_stack *astack)

{
	t_stack *final;
	t_stack *next;
	int		num;

	final = (astack->next)->next;
	next = astack->next;
	num = num_sort_three(astack, next, final);
	if (num == 1)
	{
		astack = run_sa(astack);
		astack = run_rra(astack);
	}
	else if (num == 2)
		astack = run_ra(astack);
	else if (num == 3)
		astack = run_sa(astack);
	else if (num == 4)
		astack = run_rra(astack);
	else if (num == 5)
		return (astack);
	else if (num == 6)
	{
		astack = run_rra(astack);
		astack = run_sa(astack);
	}
	return (astack);
}

int		simple_check_sort(t_stack *astack)
{
	if (astack->next)
	{
		if (astack->num < (astack->next)->num)
			return (0);
		else 
			run_ra(astack);
	}
	return (0);
}

int	*check_pp_b_min(t_stack *astack, t_stack *bstack)
{
	t_stack *bnext_stack;
	t_stack *final_stack;
	
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

t_stack	*run_pb_min(t_stack *astack, t_stack *bstack)
{
	t_stack *next_astack;
	t_stack *checkb;
	int		count;

	count = 1;
	checkb = bstack;
	next_astack = astack->next;
	if (checkb->next)
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

t_stack *check_pp_min_run(t_stack *astack, t_stack *f_stack, int pivot, int f_num)
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
		astack = check_pp_min_run(astack, final_stack, pivot, f_num);
	return (astack);
}

t_stack	*start_sort_min(t_stack *astack, t_stack *bstack, t_stack *tem, int argc)
{
	int	f_num;
	int	pivot;
	
	pivot = find_pivot_min(argc, tem);
	while (astack->front)
		astack = astack->front;
	while (bstack->front)
		bstack = bstack->front;
	while (tem->next)
		tem = tem->next;
	f_num = tem->num;
	if (!check_sort(astack, bstack))
	{
		astack = check_pp_min(astack, bstack, pivot, f_num);
		start_sort_min(astack, bstack, tem, argc);
	}
	else
	{
		astack = end_sort(astack, bstack);
		return (astack);	
	}
	return (astack);
}

t_stack *simple_check_sort_five(t_stack *astack, t_stack *bstack, t_stack *tem, int argc)

{
	int	pivot;
	int	count;

	count = 0;
	pivot = find_pivot_min(argc, tem);
	while (count < 5)
	{
		if (astack->num < pivot)
			astack = run_pb_min(astack, bstack);
		else
			astack = run_ra(astack);
		astack = astack->next;
		while (astack->front)
			astack = astack->front;
		count++;
	}
	astack = simple_check_sort_three(astack);
	if (bstack->front)
		bstack = bstack->front;
	if (bstack->num < (bstack->next)->num)
		bstack = run_sb(bstack);
	astack = run_pa_min(astack, bstack);
	bstack = bstack->next;
	astack = run_pa_min(astack, bstack);
	return (astack);
}

int	main(int argc, char *argv[])
{
	t_stack		*temstack;
	int			check;
	t_stack		*astack;
	t_stack		*bstack;

	check = 0;
	temstack = set_stack(0);
	astack = set_stack(0);
	bstack = set_stack(0);
	while (argv[++check])
		setting_stack(temstack, argv[check], check, astack);
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
//	 system("leaks push_swap");
	return (0);
}
