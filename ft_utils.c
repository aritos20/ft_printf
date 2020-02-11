/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:24:55 by antmarti          #+#    #+#             */
/*   Updated: 2020/02/05 17:40:36 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_counter(t_print *print)
{
	int numb;

	numb = 0;
	if (ft_isdigit(print->format[print->pos]))
	{
		numb = ft_atoi(&print->format[print->pos]);
		while (ft_isdigit(print->format[print->pos]))
			print->pos++;
	}
	return (numb);
}

void		*ft_ast(t_print *print, void *arg)
{
	int	num;

	num = (int)arg;
	if (print->flags->ast == 1 || print->flags->ast == 3)
	{
		if ((int)arg < 0)
		{
			print->flags->minus = 1;
			print->flags->zero = 0;
			num *= -1;
		}
		print->flags->width = num;
		arg = va_arg(print->list, void *);
		num = (int)arg;
	}
	if (print->flags->ast == 2 || print->flags->ast == 3)
	{
		if ((int)arg < 0)
			print->flags->dot = 0;
		print->flags->precision = (int)arg;
		arg = va_arg(print->list, void *);
	}
	return ((void *)arg);
}

void		ft_find_x(t_print *print)
{
	if (print->format[print->pos] == 'x')
		print->type = 'x';
	else
		print->type = 'X';
}

void		ft_converse(t_print *print, void *arg)
{
	if (print->format[print->pos] == 'c')
		ft_type_c(print, arg);
	else if (print->format[print->pos] == 's')
		ft_type_s(print, arg);
	else if (print->format[print->pos] == 'd' ||
	(print->format[print->pos] == 'i'))
		ft_type_d(print, arg);
	else if (print->format[print->pos] == 'u')
	{
		print->type = 'u';
		ft_type_d(print, arg);
	}
	else if (print->format[print->pos] == 'p')
	{
		print->type = 'p';
		ft_type_p(print, arg);
	}
	else if (print->format[print->pos] == 'x' ||
	print->format[print->pos] == 'X')
	{
		ft_find_x(print);
		ft_type_x(print, arg);
	}
	return ;
}
