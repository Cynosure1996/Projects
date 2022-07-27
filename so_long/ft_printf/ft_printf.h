/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:02:46 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/19 11:33:42 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		hex(unsigned int nbr, int n);
int		parse(const char *s, va_list ap);
int		ito2(unsigned int num);
int		ito(int num, int n);
int		ft_putchar(char n);
int		ft_putnbr(int n);
int		ft_putstr(char *s);

#endif
