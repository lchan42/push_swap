/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:53 by lchan             #+#    #+#             */
/*   Updated: 2022/03/31 18:32:43 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include "libraries/libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				rank;
	int				index;
	struct s_stack  *previous;
	struct s_stack  *next;
}t_stack;

typedef struct s_pile
{
	t_stack *a;
	t_stack *b;
	t_list	*mvtbook;
}t_pile;

//push_swap_utils.c
int		strchr_booleen(char c, char *str);
int		ft_ps_is_even_nbr(int nbr);

//push_swap_entrycheck.c
int		check_ascii(char **av);
char	*find_next_nbr(char *current_position, int *line, char **av);
int		check_overflow(int ac, char **av);
int		check_duplicate(int ac, char **av);
int		entry_check(int ac, char **av);

//push_swap_buildstack.c
t_stack	*ft_ps_nod_init(int value, int index);
t_stack	*ft_ps_stack_new_addback(t_stack **head, int value, int index);
t_stack *ft_ps_buildstack(int ac, char **av);

//movement_a.c
void	ft_ps_swap_a(t_stack **head, t_list **mvtbook);
void	ft_ps_push_a(t_stack **dst, t_stack **src, t_list **mvtbook); // b--->a
void	ft_ps_rotate_a(t_stack **head, t_list **mvtbook); //need more check
void	ft_ps_reverse_a(t_stack **head, t_list **mvtbook);


//movement_b.c
void	ft_ps_swap_b(t_stack **head, t_list **mvtbook);
void	ft_ps_push_b(t_stack **dst, t_stack **src, t_list **mvtbook); //a--->b
void	ft_ps_rotate_b(t_stack **head, t_list **mvtbook); //need more check
void	ft_ps_reverse_b(t_stack **head, t_list **mvtbook);


//stacklen.c
int     ft_ps_stacklen(t_stack *head);
int     ft_ps_chunck_len(t_stack *head);
int     ft_ps_chunckmax_len(t_stack *head);
int		ft_ps_target_chklen(t_stack *head, int index);

//find_pivot.c
int     ft_ps_findpivot(t_stack *head);
int		ft_ps_chunckpivot(t_stack *head);
int		ft_ps_targeted_chunckpivot(t_stack *head, int index);

//sorted_checker.c
int     ft_ps_sorted_checker(t_stack *head);
int     ft_ps_sorted_checker_a_n(t_stack *head, int n);
int     ft_ps_sorted_checker_b_n(t_stack *head, int n);
int		ft_ps_is_sorted(t_stack *head);

//sort_6_cir.c
void    ft_ps_sort_b2(t_stack **stack_b, t_list **mvtbook);
void    ft_ps_sort_b3_cir(t_stack **stack_b, t_list **mvtbook);
void    ft_ps_sort_b6_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);


void    ft_ps_sort_a2(t_stack **stack_a, t_list **mvtbook);
void	ft_ps_sort_back_a_cir(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int count);
void    ft_ps_sort_a3_cir(t_stack **stack_a, t_list **mvtbook);
void    ft_ps_sort_a6_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);

//ft_smartrotation // -------> Warning apparently Smart rot need intern_pivot to work properly for a 
void    ft_ps_targetedrot(t_stack **stack, t_list **mvtbook, t_stack *target, char *mvt);
int     ft_ps_smart_a_bis(t_stack **tmp, t_stack **r_tmp, int pivot, int len);
int     ft_ps_smartrotation_a(t_stack **stack, t_list **mvtbook, int pivot);
int     ft_ps_smart_b_bis(t_stack **tmp, t_stack **r_tmp, int pivot, int len);
int     ft_ps_smartrotation_b(t_stack **stack, t_list **mvtbook, int pivot);


//sort_3.c
void	ft_ps_sort_back_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int count);
void	ft_ps_pushcnt_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *count);
void    ft_ps_sortcnt_b3(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *count);
void    ft_ps_sort_b3(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void    ft_ps_sort_b3_bis(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);

void	ft_ps_sortsmall_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int count);
void	ft_ps_sort_back_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int count);
void    ft_ps_sort_a3(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void    ft_ps_sort_a3_bis(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);





int     ft_ps_push_b_count(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
int     ft_ps_push_a_count(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void    ft_ps_push_back_a_n(t_stack **dst, t_stack **src, t_list **mvtbook, int n);
void    ft_ps_push_back_b_n(t_stack **dst, t_stack **src, t_list **mvtbook, int n);
void    ft_ps_sort_a5(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);

// sub_pivot.c
void	ft_ps_pivot_mark(t_stack *head, int pivot); //not usefull in the algo. here for testing
int	ft_ps_intern_pivot_a(int chunck_len, int pivot);
int	ft_ps_intern_pivot_b(int chunck_len, int pivot);
//int	ft_ps_subpivot(t_stack *head, int pivot);
//int ft_ps_count_underpivot(t_stack *head, int pivot);
//int ft_ps_count_overpivot(t_stack *head, int pivot);

void	ft_ps_underpivotpush_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	ft_ps_orgapush_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int subpivot);
void	ft_ps_recursivepush(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);

//scan_push.c
void	ps_reverseback_a(t_stack **stack_a, t_list **mvtbook, int index);
void	ps_reverseback_b(t_stack **stack_b, t_list **mvtbook, int index);
void	ps_rotscanb_push_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *len);
void	ps_revscanb_push_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *len);
void	ps_chunck_scanpush_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);

//stack_juggle_opt.c



//get_extrem_chunck_val.c++
int		ft_ps_min_index(t_stack *head);
int		ft_ps_max_index(t_stack *head);

//chunckorganised_push.c++
void	ft_ps_pushorganise_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot);
void	ft_ps_pushorganise_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot);
void	ps_chkorga_pb(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	ps_chkorga_pa(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);

//mark_sorted.c++
void	ft_ps_resetchunck(t_stack *stack);
void	ft_ps_marksorted_a(t_stack *stack_a, t_stack *stack_b);
void	ft_ps_marksorted_b(t_stack *stack_a, t_stack *stack_b);
void	ft_ps_mark_pb(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot);

//recursive_presort.c
void	ft_ps_pass_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	ps_first_cut(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	ft_ps_recsort_a(t_stack **stack_a, t_stack **stack_b, t_list**mvtbook);
void	ft_ps_sort(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);




//chunck_juggle_opt.c
void	ft_ps_chkbsort_a(t_stack **a, t_stack **b, t_list **m);

//longest_sub_utils.c
int 	**ps_chunck_cpy(t_stack *stk, int len);
int 	ps_tab_len(int **tab);
void	ps_printtab(int **tab); //gonna have to delete that eventually;

//longest_sub_get.c
int	**ps_cpylower(int **tab, int current, int start, int len);
int **ps_decr_seq(int **tab, int len);
int	**ps_cpyhigher(int **tab, int current, int start, int len);
int **ps_incr_seq(int **tab, int len);
int	**ps_longest_seq(t_stack *stk, int opt);

//longest_sub_algo.c
void	long_sub_pa(t_stack **a, t_stack **b, t_list **mvtbook);

//push_swap_del.c
void	del_print_tab(char **tab);
void	del_print_stack(t_stack *head, int option);
void	del_back_print(t_stack *head);
void	del_print_mvtbook(t_list *mvtbook);
void	del_print_circular_lst(t_stack *head, char c, int opt);
void	del_test_mvt(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	del_test_sort_b3_cir(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	del_test_sort_a6_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);

void	del_test_sort_b6_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);
void	del_test_sort_a10_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);
void	del_test_sort_a3(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);
void	del_test_pushorganise_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	del_test_underover_pivot(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	del_test_underpivotpush_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	del_test_ft_ps_sort(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);

#endif
