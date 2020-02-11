/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:36:12 by antmarti          #+#    #+#             */
/*   Updated: 2020/01/17 16:26:10 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_count(unsigned long int n, int blen)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= blen;
	}
	return (i);
}

static char			*ft_append(int sign, unsigned long int n, char *b, int blen)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!(str = (char *)malloc((ft_count(n, blen) + sign + 1) * sizeof(char))))
		return (0);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if (sign != 0)
	{
		str[i] = '-';
		i++;
	}
	str[ft_count(n, blen) + i] = '\0';
	while (n > 0)
	{
		i++;
		str[ft_count(n, blen) - 1 + sign] = b[n % blen];
		n /= blen;
	}
	return (str);
}

char				*ft_itoa(long long int n, char *base, int blen)
{
	char				*str;
	int					sign;
	unsigned long int	nb;

	sign = 0;
	str = 0;
	if (n < 0)
	{
		sign++;
		nb = n * (-1);
	}
	else
		nb = n;
	return (ft_append(sign, nb, base, blen));
}
