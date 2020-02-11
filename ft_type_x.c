/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:31:45 by agianico          #+#    #+#             */
/*   Updated: 2020/01/20 17:27:01 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_x(t_print *print, void *arg)
{
	char	*d;
	int		i;

	i = -1;
	if (print->type == 'x')
		d = ft_itoa((unsigned int)arg, "0123456789abcdef", 16);
	else
		d = ft_itoa((unsigned int)arg, "0123456789ABCDEF", 16);
	print->pos++;
	if (print->flags->width != 0 && print->flags->dot == 0)
		return (ft_width(print, d, i, (print->flags->width - ft_strlen(d))));
	else if (print->flags->width == 0 && print->flags->dot != 0)
		return (ft_precision(print, d, i,
		print->flags->precision - ft_strlen(d)));
	else if ((print->flags->width != 0) && (print->flags->dot != 0))
		ft_both(print, d, i);
	else
	{
		while (d[++i])
			ft_rep(print, 1, d[i]);
	}
	free(d);
}
