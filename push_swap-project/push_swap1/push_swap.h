/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:30:43 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/09 16:02:41 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"


# include "stdlib.h"
# include "unistd.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*front;
	struct s_stack	*next;
	int				index;
}				t_stack;

char	linked_temstack_back(int factor, t_stack *temstack);
char	linked_temstack_front(int factor, t_stack *temstack);
char	make_temstack(int factor, t_stack *temstack);
char	make_firststack(int factor, t_stack *temstack);
int	find_pivot_a(int argc, t_stack *temstack);
int	find_pivot(int argc, t_stack *temstack);

t_stack	*set_stack(int index, int factor);
char	check_factor(long long factor);
void	setting_stack(t_stack *temstack, char *argv, int i, t_stack *astack);
void	setting_stack_tem(t_stack *temstack, int argv, int i);

void	print_error(void);
void	free_stack(t_stack *stack, t_stack *astack, t_stack *bstack);
char	make_astack(int factor, t_stack *astack);


t_stack	*start_sort(t_stack *astack, t_stack *bstack, int pivot, t_stack *tem);

t_stack	*check_pp(t_stack *astack, t_stack *bstack, int count, t_stack *tem);

#endif
