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
	// 연결리스트 모두 메모리 해제 시켜야 한다.
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

char	check_sort_b(t_stack *bstack)
{
	// printf("check_sort_b ===== %d\n", bstack->num);
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

void	run_rb(t_stack *bstack)
{
	// 첫번째 마지막으로 이동
	t_stack *final_stack;
	t_stack *next_stack;

	next_stack = bstack->next;
	final_stack = bstack;
	while (final_stack->next)
		final_stack = final_stack->next;
		
	// 첫번째 마지막으로
	bstack->front = final_stack;
	bstack->next = NULL;
	final_stack->next = bstack;

	// 두번째를 제일 위로
	next_stack->front = NULL;
	write(1, "rb\n", 3);
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

	// 두번째 스택 앞으로 이동
	next_stack->front = NULL;
	next_stack->next = bstack;

	// 첫번째 스택 뒤로 이동
	bstack->front = next_stack;
	
	if (temp)
	{
		third_stack = temp;
		bstack->next = third_stack;
		third_stack->front = bstack;
		// printf ("how timesssssssss========== \n");
	}
	else 
		bstack->next = NULL;

	write(1, "sb\n", 3);
	return (next_stack);
}

t_stack	*run_rrb(t_stack *bstack)
{
	// 마지막 첫번째로 이동
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

	// final 맨 위로 올림
	final_stack->front = NULL;
	final_stack->next = bstack;

	bstack->front = final_stack;

	write(1, "rra\n", 4);
	return (final_stack);
}

int	*check_pp_b(t_stack *astack, t_stack *bstack)
{
	// 내림차순 5 4 3 2 1 정렬해야한다.
	t_stack *bnext_stack;
	t_stack *final_stack;
	while (bstack->front)
		bstack = bstack->front;
	bnext_stack = bstack->next;
	final_stack = bstack;
	while (final_stack->next)
		final_stack = final_stack->next;
	// final num 이 더 크면 맨위로 올린다면 swapb 해야 한다.
	// if (bstack->num > bnext_stack->num && bstack->num > final_stack->num)
	// 	return (0);
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


	// if (bstack->num < final_stack->num && bstack->num > bnext_stack->num)
	// 	run_rb(bstack);
	// else if (bstack->num < bnext_stack->num)
	// 	run_sb(bstack);
	// else if (bstack->num > final_stack->num)
	// 	run_rrb(bstack);

	// printf("what------------ \n");
	if (!check_sort_b(bstack))
	{
		// printf("hter what------------ \n");
		check_pp_b(astack, bstack);
	}
	return (0);
}

t_stack	*run_pb(t_stack *astack, t_stack *bstack)
{
	t_stack *next_astack;
	t_stack *checkb;
	int		count;

	t_stack *b;
	b = bstack;
	
	count = 0;
	checkb = bstack;
	next_astack = astack->next;
	// printf("run pb astack ==== %d\n", astack->num);
	while (checkb)
	{
		checkb = checkb->next;
		count++;
	}
	
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
	// printf ("count === ??? %d index ==  %d \n",count, bstack->index);
			while (b->front)
				b = b->front;
			while (b)
			{
				// printf("final b======== %d\n", b->num);
				b = b->next;
			}
	
	next_astack->front = NULL;
	write(1, "pb\n", 3);
	if (bstack->front)
	{
		check_pp_b(next_astack, bstack);
		// printf("checkp pp === \n");
	}
	return (next_astack);
}

t_stack	*run_ra(t_stack *astack)
{
	// 첫번째 마지막으로 이동
	t_stack *final_stack;
	t_stack *next_stack;

	next_stack = astack->next;
	final_stack = astack;
	while (final_stack->next)
		final_stack = final_stack->next;
		
	// 첫번째 마지막으로
	astack->front = final_stack;
	astack->next = NULL;
	final_stack->next = astack;

	// 두번째를 제일 위로
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

	// 두번째 스택 앞으로 이동
	next_stack->front = NULL;
	next_stack->next = astack;

	// 첫번째 스택 뒤로 이동
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
	// 마지막 첫번째로 이동
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
	
	// final 맨 위로 올림
	final_stack->front = NULL;
	final_stack->next = astack;
	//printf("========= %d\n", final_stack->num);
	astack->front = final_stack;

	
	write(1, "rra\n", 4);
	// if (final_stack->num > astack->num)	
	// 	run_sa(final_stack);
	return (final_stack);
}

char	check_sort(t_stack *astack, t_stack *bstack, int pivot)
{
	// printf ("check sort how!!!!!!!!! \n");
	while (astack->front)
		astack = astack->front;
	while (bstack->front)
		bstack = bstack->front;
	// printf ("aaaaaaaaa!!!!!!!!! %d \n",astack->num);
	// printf ("bbbbbbb!!!!!!!!!bbbb %d \n", bstack->num);
		// if (bstack->next)
		// {	printf ("bbbbbbb!!!!!!!!!bbbb %d \n", (bstack->next)->num);
			
		// if ((bstack->next)->next)
		// 	printf ("bbbbbbb!!!!!!!!!bbbb %d \n", ((bstack->next)->next)->num);
		// 	}
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
	// printf("htereerer \n");
	while (!(astack->num = pivot))
		astack = run_ra(astack);
	return (astack);
}

t_stack	*check_pp(t_stack *astack, t_stack *bstack, int pivot, int f_num)
{
	t_stack	*anext_stack;
	t_stack	*final_stack;

	anext_stack = astack->next;
	final_stack = astack;
	while (final_stack->next)
		final_stack = final_stack->next;
	
	if (astack->num < pivot)
		astack = run_pb(astack, bstack);

	else if (check_sort_re(astack))
		run_reverse(astack, pivot);
	// final 반대	
	else if (astack->num < final_stack->num && astack->num < anext_stack->num && astack->num != pivot && astack->num != f_num)
	{
		astack = run_rra(astack, pivot);
		astack = run_sa(astack);
	}
	// next 반대
	else if (astack->num < final_stack->num && astack->num < anext_stack->num && astack->num != pivot && astack->num != f_num)
		run_sa(astack);
	// 모두 반대
	else if (astack->num < final_stack->num && astack->num > anext_stack->num && astack->num != pivot && astack->num != f_num)
	{
		astack = run_rra(astack, pivot);
		astack = run_sa(astack);
		astack = run_ra(astack);
		astack = run_sa(astack);
	}
	else
		run_ra(astack);
	return (astack);
}



void	run_pa(t_stack *astack, t_stack *bstack)
{
	astack->front = bstack;
	bstack->next = astack;
	bstack->front = NULL;
	write(1, "pa\n", 3);
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
			// printf("second?? \n");
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

t_stack	*start_sort(t_stack *astack, t_stack *bstack, int pivot, t_stack *tem)
{
	t_stack *a;
	t_stack *b;
	int	f_num;
	
		// printf ("start sort \n");
	
	while (astack->front)
		astack = astack->front;
	while (bstack->front)
		bstack = bstack->front;
	while (tem->next)
		tem = tem->next;
	f_num = tem->num;
	
	// a = astack;
	// while (a)
	// {
	// 	printf("start sort aaaaa = %d\n", a->num);
	// 	a = a->next;
	// }
	// b = bstack;
	// printf("\n");
	// while (b)
	// {
	// 	printf("start sort bbbbb = %d\n", b->num);
	// 	b = b->next;
	// }


	if (!check_sort(astack, bstack, pivot))
	{
		astack = check_pp(astack, bstack, pivot, f_num);
		start_sort(astack, bstack, pivot, tem);
	}
	else
	{
		astack = end_sort(astack, bstack);
		return (astack);	
	}
	// end sort에서 리스트 제일 앞부분을 가르키도록 확인
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
	int			pivot;
	t_stack		*astack;
	t_stack		*bstack;

	pivot = 0;
	temstack = set_stack(0, 0);
	astack = set_stack(0, 0);
	bstack = set_stack(0, 0);
	while (argv[++pivot])
		setting_stack(temstack, argv[pivot], pivot, astack);
	
	if (argc <= 3)
		simple_check_sort(astack);
	else 
	{
		pivot = find_pivot(argc, temstack);
		astack = start_sort(astack, bstack, pivot, temstack);

		// printf( "pivot ========= %d\n",pivot);
	}

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

	// free_stack(temstack, astack, bstack);

	
	// while (astack->front)
	// 	astack = astack->front;
	// while (astack)
	// 	{
	// 		printf("final astack======== %d\n", astack->num);
	// 		astack = astack->next;
	// 	}
	
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
	
	
	//system("leaks a.out");

	
	return (0);
}
