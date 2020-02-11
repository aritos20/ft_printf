/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:41:49 by agianico          #+#    #+#             */
/*   Updated: 2020/01/20 13:02:01 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_percent(t_print *print)
{
	int		dif;

	if (print->flags->width != 0 && print->flags->minus == 0
	&& print->flags->zero == 0)
	{
		dif = print->flags->width - 1;
		ft_rep(print, dif, ' ');
		write(1, &print->format[print->pos], 1);
	}
	else if (print->flags->width != 0 && print->flags->minus != 0)
	{
		write(1, &print->format[print->pos], 1);
		dif = print->flags->width - 1;
		ft_rep(print, dif, ' ');
	}
	else if (print->flags->zero != 0)
	{
		dif = print->flags->width - 1;
		ft_rep(print, dif, '0');
		write(1, &print->format[print->pos], 1);
	}
	else
		write(1, &print->format[print->pos], 1);
	print->len++;
	print->pos++;
}
