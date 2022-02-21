/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:46:49 by lchan             #+#    #+#             */
/*   Updated: 2022/01/25 20:04:00 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "# +-0."
# define HEXABASE "0123456789abcdef"

typedef struct s_list
{
	void			*content;
	int				result;
	struct s_list	*next;
}	t_list;

typedef struct s_struct
{
	char	specifier;
	int		flag_value;
	int		width;
	int		precision;
	char	*content;
}	t_struct;

enum e_flags
{
	ALTERNATE_FORME = 1,
	SPACE = 2,
	PLUS_SIGN = 4,
	LEFT_ADJUSTMENT = 8,
	ZERO = 16,
	PRECISION = 32,
};

//utils
//	utils_one.c
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_isnonull_digit(int c);
char	*ft_strchr(const char *s, int c);
int		ft_strchr_booleen(const char *s, int c);
//	utils_two.c
void	struct_init(t_struct *t_specifier);
char	*printf_strjoin_frees2(char const *s1, char const *s2);
char	*printf_strjoin_free(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, int len);

//chained_list.c
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew_with_count(void *content, int count);
void	ft_lstadd_back(t_list **alst, t_list *new);
int		ft_print_list_result(t_list *alst);
void	free_list(t_list *alst);

//add_sign_to_content.c
void	ft_add_space_or_plus(char **t_specifier_content, int flag_value);

//add_padding.c
void	ft_add_padding_onright_cnull(t_struct *t_specifier,
			char **padded_content);
void	ft_add_padding_onright(t_struct *t_specifier);
void	ft_add_padding_onleft_bis(int content_len,
			t_struct *t_specifier, char **padded_content, int *i);
void	ft_add_padding_onleft(int content_len, t_struct *t_specifier);
void	ft_add_padding(t_struct *t_specifier);

//add_precision.c
void	ft_precision_case_null(t_struct *t_specifier);
void	ft_precision_case_signed(t_struct *t_specifier, int content_len);
void	ft_precision_case_0x(t_struct *t_specifier, int content_len);
void	ft_precision_case_unsigned(t_struct*t_specifier, int content_len);
void	ft_add_precision(t_struct *t_specifier);

//add_content_to_chained_list.c
void	ft_add_str_content(char *str, t_list **strchain);
void	ft_add_specifier_content(t_list **strchain, t_struct *t_specifier);

//specifier_tree
//	case_csp.c
void	ft_case_c(int argument, char **t_specifier_content);
void	ft_case_s(char *argument, t_struct *t_specifier);
int		ft_convertbase_size(unsigned long long int argument, int base);
char	*ft_printf_itoa_hexa(int len,
			unsigned long long int argument, char specifier);
void	ft_case_p(unsigned long long int argument, char **t_specifier_content);
//	case_duxxmajpercent.c
void	ft_case_d(int argument, char **t_specifier_content, int flag_value);
void	ft_case_u(unsigned int argument, char **t_specifier_content);
void	ft_case_x(unsigned int argument, t_struct *t_specifier);
void	ft_case_xmaj(unsigned argument, t_struct *t_specifier);
void	ft_case_percent(char **t_specifier_content);
//	specifier_tree.c
void	specifier_tree(char specifier, va_list arg_list, t_struct *t_specifier);

//cursor_jump_specifier.c
int		jump_specifier(char *str);

//parsing.c
char	*parsing_bonus_digit(char *str, t_struct *t_specifier);
void	parsing_bonus_flag_overwrites(int *flag_value, char specifier);
void	parsing_bonus_flag_value(char flag, int *flag_value);
void	parsing_bonus(char *str, t_struct *t_specifier);
int		parsing(char *str, t_list **strchain, va_list arg_list);

//ft_printf.c
int		ft_printf(const char *str, ...)
		__attribute__((format (printf, 1, 2)));

#endif
