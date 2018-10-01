/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:19:56 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 19:20:46 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef	struct			s_format
{
	char				zero;
	char				plus;
	char				minus;
	char				space;
	char				hash;
	char				percent;
	int					widt;
	int					prs;
	int					prsflag;
	char				lenght;
	char				spec;
	char				numsign;
	size_t				len;
	size_t				lenout;
	char				*out;
}						t_format;

void					pf_putchar(t_format *list, char s);
char					*pf_tolower(t_format *list, char *str);
int						pf_addpre(t_format *list, int k);
void					pf_addpost(t_format *list, int k);
int						set_flag(t_format *list, char *arg);
int						is_handler(char c);
void					len_to_skip(t_format *list, char *format);
int						ft_printf(const char *format, ...);
char					*ft_itoau(ssize_t n);
char					*get_specifier(const char *str, t_format *list);
void					format_str(t_format *list, char *arg);
void					char_to_str(t_format *list, va_list arg);
char					*get_new_width(t_format *list, char *str);
void					arg_to_uox_str(t_format *list, size_t ar);
int						get_arg_u_o_x(t_format *list, va_list arg);
size_t					get_len_int(t_format *list, va_list arg);
char					*new_width_str(t_format *list, char *str);
void					get_width(char *str, t_format *list);
void					get_precision(char *str, t_format *list);
void					get_arg_str(t_format *list, va_list ar);
void					get_lenght(char *str, t_format *list);
char					*add_presicion(t_format *list, char *str);
void					pf_putstr(t_format *list, char *str);
void					get_arg_int(t_format *list, va_list ar);
char					*makewchar(t_format *list, unsigned int n);
void					format_wchar_str(wchar_t *str, t_format *list);
void					format_no_spec(t_format *list, char *str);
void					get_flag(char *str, t_format *list);
int						pre_width_u_o_x(t_format *list, char *str);

#endif
