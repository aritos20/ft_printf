/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:27:31 by agianico          #+#    #+#             */
/*   Updated: 2020/01/09 12:38:44 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_s(t_print *print, void *arg)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)arg;
	if (!str)
		str = "(null)";
	if (print->flags->minus == 1)
		ft_str_minus(print, str, i);
	else if (print->flags->dot != 0 && (print->flags->precision <
	(int)ft_strlen(str)))
	{
		ft_rep(print, print->flags->width - print->flags->precision, ' ');
		while (str[++i] && (i < print->flags->precision))
			ft_rep(print, 1, str[i]);
	}
	else
	{
		ft_rep(print, print->flags->width - ft_strlen(str), ' ');
		while (str[++i])
			ft_rep(print, 1, str[i]);
	}
	print->pos++;
}

void		ft_str_minus(t_print *print, char *str, int i)
{
	if (print->flags->dot != 0 && (print->flags->precision <
	(int)ft_strlen(str)))
	{
		while (str[++i] && (i < print->flags->precision))
			ft_rep(print, 1, str[i]);
		ft_rep(print, print->flags->width - print->flags->precision, ' ');
	}
	else
	{
		while (str[++i])
			ft_rep(print, 1, str[i]);
		ft_rep(print, print->flags->width - ft_strlen(str), ' ');
	}
}
