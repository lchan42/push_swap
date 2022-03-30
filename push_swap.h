/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:53 by lchan             #+#    #+#             */
/*   Updated: 2022/03/30 18:28:16 by lchan            ###   ########.fr       */
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

//movement.c
//void	swap(t_stack **head);
//void	push(t_stack** head_a, t_stack **head_b);
//void	rotate(t_stack **head_a, t_stack **head_b);
//void	reverse_rotate(t_stack **head_a, t_stack **head_b);

//void	swap(t_stack **head, t_list **mvtbook, char *mvt);
//void	push(t_stack **dst, t_stack **src, t_list **mvtbook, char *mvt);
//void	rotate(t_stack **head_a, t_stack **head_b, t_list **mvtbook, char *mvt);
//void	reverse_rotate(t_stack **head_a, t_stack **head_b, t_list **mvtbook, char *mvt);

void	ft_ps_swap_a(t_stack **head, t_list **mvtbook);
void	ft_ps_push_a(t_stack **dst, t_stack **src, t_list **mvtbook); // b--->a
void	ft_ps_rotate_a(t_stack **head, t_list **mvtbook); //need more check
void	ft_ps_reverse_a(t_stack **head, t_list **mvtbook);

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

//sort_9_cirhybrid.c --> use of sort cir_6 and a normal sort for b

//ft_smartrotation // -------> Warning apparently Smart rot need intern_pivot to work properly for a 
void    ft_ps_targetedrot(t_stack **stack, t_list **mvtbook, t_stack *target, char *mvt);
int     ft_ps_smart_a_bis(t_stack **tmp, t_stack **r_tmp, int pivot, int len);
int     ft_ps_smartrotation_a(t_stack **stack, t_list **mvtbook, int pivot);
int     ft_ps_smart_b_bis(t_stack **tmp, t_stack **r_tmp, int pivot, int len);
int     ft_ps_smartrotation_b(t_stack **stack, t_list **mvtbook, int pivot);

//

//sorting_algo.c
//
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



//stack_juggle.c
void    ft_ps_pushorganise_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot);
void    ft_ps_pushorganise_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot);
void    ft_ps_pass_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void    ft_ps_pass_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void    ft_ps_juggle(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);

//scan_push.c
void	ps_reverseback_a(t_stack **stack_a, t_list **mvtbook, int index);
void	ps_reverseback_b(t_stack **stack_b, t_list **mvtbook, int index);
void	ps_rotscanb_push_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *len);
void	ps_revscanb_push_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *len);
void	ps_chunck_scanpush_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);

//stack_juggle_opt.c
//
int	ft_ps_min_index(t_stack *head);
int	ft_ps_max_index(t_stack *head);

void	ft_ps_resetchunck(t_stack *stack);
void	ft_ps_marksorted_a(t_stack *stack_a, t_stack *stack_b);
void	ft_ps_marksorted_b(t_stack *stack_a, t_stack *stack_b);

int	ft_ps_is_even_nbr(int n); //--> should go in utilsi
void	ft_ps_recsort_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	ft_ps_sort(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
//sorting_5.c as I decided to go thought recursive, I'm not sure that optimising this will be useful. Lets see.


//chunck_juggle_opt.c
void	ft_ps_chkbsort_a(t_stack **a, t_stack **b, t_list **m);

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
