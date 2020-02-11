/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:02:36 by antmarti          #+#    #+#             */
/*   Updated: 2020/01/22 20:41:09 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_crabs(t_print *print, void *arg)
{
	print->pos++;
	ft_flags(print);
	if (print->format[print->pos] == '%')
	{
		if (print->flags->ast != 0)
		{
			arg = va_arg(print->list, void *);
			arg = ft_ast(print, arg);
		}
		ft_type_percent(print);
	}
	else
	{
		arg = va_arg(print->list, void *);
		if (print->flags->ast != 0)
			arg = ft_ast(print, arg);
		ft_converse(print, arg);
	}
}

int		ft_printf(const char *format, ...)
{
	t_print		*print;
	void		*arg;

	arg = NULL;
	if (!(print = malloc(sizeof(t_print))))
		return (-1);
	if (format)
	{
		va_start(print->list, format);
		ft_init(print, format);
		while (print->format[print->pos])
		{
			if (print->format[print->pos] == '%')
				ft_print_crabs(print, arg);
			else
			{
				write(1, &((const void *)print->format)[print->pos], 1);
				print->len++;
				print->pos++;
			}
		}
	}
	return (print->len);
}
