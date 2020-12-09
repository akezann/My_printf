/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:09:52 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/28 19:38:52 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct	s_specs
{
	int		width;
	int		precision;
	int		fg_zero;
	int		fg_minus;
	int		conversion;
	va_list args;
}				t_specs;

typedef struct	s_parseprint
{
	int width_print;
	int prec_print;
}				t_parseprint;

int				ft_printf(char *format, ...);
void			parse_spec(char **str, t_specs *specs);
int				printchar_time(char c, int time);
int				len_digit(long int n);
int				check_pos(long int n);
void			check_width(t_specs *specs);
char			*conv_u_x(unsigned int n, int base);
char			*conv_l_x(unsigned int n, int base);
char			*conv_ptr(unsigned long n, int base);
void			init_parseprint(t_parseprint *parseprint);
int				printstr_len(char *str, int len);
int				print_arg(t_specs *specs, t_parseprint *parseprint);
int				print_c(t_specs *specs);
int				print_int(t_specs *specs, t_parseprint *parseprint);
int				print_s(t_specs *specs, t_parseprint *parseprint);
int				print_u(t_specs *specs, t_parseprint *parseprint);
int				print_p(t_specs *specs, t_parseprint *parseprint);
int				print_l_x(t_specs *specs, t_parseprint *parseprint);
int				print_u_x(t_specs *specs, t_parseprint *parseprint);
int				print_p(t_specs *specs, t_parseprint *parseprint);
int				print_perc(t_specs *specs);
#endif
