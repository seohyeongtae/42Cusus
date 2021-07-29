/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:30:43 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/27 16:33:54 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "unistd.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*front;
	struct s_stack	*next;
	int				index;
}				t_stack;

void	print_error(void);
void	free_stack(t_stack *stack);
int		find_pivot_min(int argc, t_stack *temstack);
int		find_pivot(int argc, t_stack *temstack);

t_stack	*run_pa(t_stack *astack, t_stack *bstack);
t_stack	*run_pb(t_stack *astack, t_stack *bstack);
t_stack	*run_sb(t_stack *bstack);
t_stack	*run_sa(t_stack *astack);

t_stack	*run_rrb(t_stack *bstack);
t_stack	*run_rra(t_stack *astack);
t_stack	*run_rb(t_stack *bstack);
t_stack	*run_ra(t_stack *astack);

char	check_sort_b(t_stack *bstack);
char	check_sort_re(t_stack *astack);
int		simple_check_sort(t_stack *astack);
char	check_sort(t_stack *astack, t_stack *bstack);

t_stack	*check_pp_b(t_stack *astack, t_stack *bstack, int pivot, int count);
t_stack	*check_b(t_stack *astack, t_stack *bstack, int count);
t_stack	*check_pp_a_s(t_stack *astack, t_stack *bstack, int ra, int pb);
t_stack	*check_pp_a(t_stack *astack, t_stack *bstack, int pivot, int count);
t_stack	*check_pp(t_stack *astack, t_stack *bstack, int count);

t_stack	*run_pa_min(t_stack *astack, t_stack *bstack);
t_stack	*run_reverse(t_stack *astack, int pivot);
t_stack	*run_pb_min(t_stack *astack, t_stack *bstack);

t_stack	*end_sort(t_stack *astack, t_stack *bstack);
t_stack	*simple_check_sort_three(t_stack *astack);
t_stack	*start_sort_min(t_stack *astack, t_stack *bstack, t_stack *tem, int a);
t_stack	*simple_check_sort_five(t_stack *astack, t_stack *b, t_stack *t, int a);
t_stack	*start_sort(t_stack *astack, int count, t_stack *tem);

int		num_sort_three(t_stack *astack, t_stack *next, t_stack *final);
int		*check_pp_b_min(t_stack *astack, t_stack *bstack);
t_stack	*pp_min_run(t_stack *astack, t_stack *f_stack, int pivot, int f_num);
t_stack	*check_pp_min(t_stack *astack, t_stack *bstack, int pivot, int f_num);

char	make_astack(int factor, t_stack *astack);
char	**make_argv(char **argv);
int		num_len(char **num);

t_stack	*set_stack(int factor);
long long	change_factor(char *check);
char	check_factor(long long factor);
void	setting_stack_tem(t_stack *temstack, int argv, int i);
void	setting_stack(t_stack *temstack, char *argv, int i, t_stack *astack);

char	linked_temstack_back(int factor, t_stack *temstack);
char	linked_temstack_front(int factor, t_stack *temstack);
char	make_firststack(int factor, t_stack *temstack);
char	make_temstack(int factor, t_stack *temstack);

int		ft_word_count(char const *s, char c);
char	*ft_word_make(char *word, char const *s, int k, int word_len);
char	**make_free(char **result, int i);
char	**ft_split2(char **result, char const *s, char c, int word_num);
char	**ft_split(char const *s, char c);

unsigned int	ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
