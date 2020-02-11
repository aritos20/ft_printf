/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:29:36 by agianico          #+#    #+#             */
/*   Updated: 2020/01/09 12:13:16 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_c(t_print *print, void *arg)
{
	int		dif;
	char	c;

	dif = 0;
	c = (char)arg;
	if (print->flags->minus == 1)
	{
		write(1, &c, 1);
		dif = print->flags->width - 1;
		ft_rep(print, dif, ' ');
	}
	else if (print->flags->width != 0)
	{
		dif = print->flags->width - 1;
		ft_rep(print, dif, ' ');
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
	print->len++;
	print->pos++;
}
