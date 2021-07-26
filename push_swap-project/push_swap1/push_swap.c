/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:23:44 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/09 17:18:52 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
} 

void	free_stack(t_stack *stack, t_stack *astack, t_stack *bstack)
{
	t_stack *temp;

	while(stack->front)
		stack = stack->front;
	while(astack->front)
		astack = astack->front;
	while(bstack->front)
		bstack = bstack->front;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
		if (astack)
			{
				temp = astack;
				astack = astack->next;
				free(temp);
			}
		if (bstack)
			{
				temp = bstack;
				bstack = bstack->next;
				free(temp);
			}
	}
}

char	make_astack(int factor, t_stack *astack)
{
	t_stack *new_stack;

	if (!(new_stack = set_stack(0, factor)))
		return (0);
	while (astack->next)
		astack = astack->next;
	astack->next = new_stack;
	new_stack->front = astack;
	return ('1');
}

char	check_sort(t_stack *astack, t_stack *bstack, int pivot)
{
	while (astack->front)
		astack = astack->front;
	while (bstack->front)
		bstack = bstack->front;
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
		new_stack = set_stack(0,0);
		new_stack->num = bstack->num;
		astack->front = new_stack;
		new_stack->next = astack;
		free(bstack);
		write(1, "pa\n", 3);
		return (bstack);
	}
	else 
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

t_stack *check_b(t_stack *astack, t_stack *bstack, int count, t_stack *tem)
{
	int	pivot;
	int	pa;
	int	rb;
	t_stack	*b;
	t_stack *b_tem;

	pa = 1;
	rb = count;
	b = bstack;
	b_tem = set_stack(0,0);
	
	while (rb > 0)
	{
		setting_stack_tem(b_tem, b->num, pa++);
		b = b->next;
		rb--;
	}
	pa = 0;
	pivot = find_pivot(count / 2, b_tem);
	free(b_tem);
	while (count > 0)
	{
		if (bstack->num >= pivot && pa++ >= 0)
		{
			bstack = run_pa(astack, bstack);
			while (astack->front)
				astack = astack->front;
		}
		else if (bstack->next && rb++ >= 0)
			bstack = run_rb(bstack);
		count--;
	
	}
	int ab;
	ab = rb;
	while (bstack->next && rb-- > 0)
		bstack = run_rrb(bstack);
	while (astack->front)
		 astack = astack->front;
	if (pa > 0)
		astack = check_pp(astack, bstack, pa, tem);
	if (ab > 0)
		bstack = check_b(astack, bstack, ab, tem);
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

t_stack	*run_rra(t_stack *astack, int pivot)
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




t_stack	*check_pp(t_stack *astack, t_stack *bstack, int count, t_stack *tem)
{
	int	pivot;
	int	pb;
	int	ra;
	t_stack	*a;
	t_stack *a_tem;

	pb = 1;
	a = astack;
	a_tem = set_stack(0,0);
	ra = count;
	while (ra > 0)
	{
		setting_stack_tem(a_tem, a->num, pb++);
		a = a->next;
		ra--;
	}
	pb = 0;
	pivot = find_pivot(count / 2, a_tem);
	free(a_tem);
	while (count > 0)
	{		
		if (astack->num < pivot && pb++ >= 0)
		{
			astack = run_pb(astack, bstack);
			while (bstack->front)
				bstack = bstack->front;
		}
		else if (astack->next && ra++ >= 0)
			astack = run_ra(astack);
		count--;
	}

	int ab;
	ab = ra;
	while (astack->next && ra-- > 0)
		astack = run_rra(astack, pivot);
	if (ab > 1)
		astack = check_pp(astack, bstack, ab, tem);
	while (bstack->front)
			bstack = bstack->front;
	if (pb > 0)
		bstack = check_b(astack, bstack, pb, tem);
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
		if (bstack->index == 1 && bstack->next)
		{
			temp = bstack->next;
			run_pa(astack, bstack);
			astack = astack->front;
			bstack = temp;
		}
		else
		{
			temp = temp->next;
			run_pa(astack, bstack);
			astack = astack->front;
		}
	}
	while (astack->front)
		astack = astack->front;
	return (astack);
}

t_stack	*start_sort(t_stack *astack, t_stack *bstack, int count, t_stack *tem)
{
	int		pivot;
	int	i;

	i = 0;
	pivot = find_pivot(count / 2, tem);
	if (!(check_sort(astack, bstack, count)))
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
		astack = check_pp(astack, bstack, (count / 2) + (count % 2), tem);
		if (!check_sort_b(bstack))
		{
			while (bstack->front)
				bstack = bstack->front;
			 bstack = check_b(astack, bstack, (count / 2) , tem);
		}
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

int	main(int argc, char *argv[])
{
	long long	factor;
	t_stack		*temstack;
	int			check;
	t_stack		*astack;
	t_stack		*bstack;

	check = 0;
	temstack = set_stack(0, 0);
	astack = set_stack(0, 0);
	bstack = set_stack(0, 0);
	while (argv[++check])
		setting_stack(temstack, argv[check], check, astack);
	
	if (argc <= 3)
		simple_check_sort(astack);
	else 
		astack = start_sort(astack, bstack, argc - 1, temstack);
	// setting_stack(temstack, "87", 1, astack);
	// setting_stack(temstack, "47", pivot, astack);
	// setting_stack(temstack, "4", pivot, astack);
	// setting_stack(temstack, "2", pivot, astack);
	// setting_stack(temstack, "5", pivot, astack);
	// setting_stack(temstack, "98", pivot, astack);
	// setting_stack(temstack, "3", pivot, astack);
	// setting_stack(temstack, "6", pivot, astack);
	// setting_stack(temstack, "7", pivot, astack);

	// pivot = find_pivot(10, temstack);
	// astack = start_sort(astack, bstack, pivot, 10);



	
	while (astack->front)
		astack = astack->front;
	while (astack)
		{
			printf("final astack======== %d\n", astack->num);
			astack = astack->next;
		}
	
	while (bstack->front)
		bstack = bstack->front;
	while (bstack)
		{
			printf("bbb final bstack======== %d\n", bstack->num);
			bstack = bstack->next;
		}
	
	free_stack(temstack, astack, bstack);
	
	// // printf("======== %d\n", astack->num);
	// // astack = astack->next;
	// // 	printf("======== %d\n", astack->num);
	// // astack = astack->next;
	// // 	printf("======== %d\n", astack->num);
	// // astack = astack->next;
	// while (temstack->front)
	// 	temstack = temstack->front;
	// while (temstack)
	// {
	// 	printf("tem======== %d\n", temstack->num);
	// 	temstack = temstack->next;
	// }
	
	
	// system("leaks a.out");

	
	return (0);
}
