/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:24:17 by agianico          #+#    #+#             */
/*   Updated: 2020/02/05 17:40:09 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_print *print, const char *format)
{
	print->format = format;
	print->len = 0;
	print->type = '0';
	print->pos = 0;
}

void	ft_init_flags(t_print *print)
{
	print->flags = malloc(sizeof(t_flags));
	print->flags->width = 0;
	print->flags->ast = 0;
	print->flags->dot = 0;
	print->flags->minus = 0;
	print->flags->zero = 0;
	print->flags->precision = 0;
}

void	ft_flags(t_print *print)
{
	ft_init_flags(print);
	if (print->format[print->pos] == '0' && print->pos++)
		if (print->format[print->pos] == '-' && print->pos++)
			print->flags->minus = 1;
		else
			print->flags->zero = 1;
	else if (print->format[print->pos] == '-' && print->pos++)
		print->flags->minus = 1;
	print->flags->width = ft_counter(print);
	if (print->format[print->pos] == '*' && print->pos++)
		print->flags->ast = 1;
	if (print->format[print->pos] == '.' && print->pos++)
	{
		print->flags->dot = 1;
		print->flags->precision = ft_counter(print);
	}
	if (print->format[print->pos] == '*' && print->pos++)
	{
		if (print->flags->ast == 0)
			print->flags->ast = 2;
		if (print->flags->ast == 1)
			print->flags->ast = 3;
	}
}
