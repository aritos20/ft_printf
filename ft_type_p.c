/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:34:19 by agianico          #+#    #+#             */
/*   Updated: 2020/01/20 13:03:09 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_p(t_print *print, void *arg)
{
	char	*d;
	int		i;

	i = -1;
	d = ft_itoa((unsigned long int)arg, "0123456789abcdef", 16);
	print->pos++;
	if (print->flags->width != 0 && print->flags->dot == 0)
		return (ft_width(print, d, i, (print->flags->width -
		ft_strlen(d) - 2)));
	else if (print->flags->width == 0 && print->flags->dot != 0)
		return (ft_precision(print, d, i,
		print->flags->precision - ft_strlen(d)));
	else if ((print->flags->width != 0) && (print->flags->dot != 0))
		ft_both(print, d, i);
	else
	{
		ft_rep(print, 1, '0');
		ft_rep(print, 1, 'x');
		while (d[++i])
			ft_rep(print, 1, d[i]);
	}
	free(d);
}
