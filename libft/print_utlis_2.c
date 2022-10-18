/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utlis_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:38:20 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/08 15:47:16 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(long n, int count)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		count = ft_print_char('-', count);
		nbr = -n;
	}
	if (nbr >= 10)
		count = ft_print_int(nbr / 10, count);
	count = ft_print_char((nbr % 10 + '0'), count);
	return (count);
}

int	ft_check_hex(unsigned int nbr, int count, char c)
{
	if (nbr == 0)
	{
		count = ft_print_char('0', count);
		return (count);
	}
	else
		count = ft_print_hex(nbr, count, c);
	return (count);
}

int	ft_print_hex(unsigned int nbr, int count, char c)
{
	unsigned int	rem;

	rem = 0;
	if (nbr)
	{
		rem = nbr % 16;
		count = ft_print_hex(nbr / 16, count, c);
		if (rem < 10)
			count = ft_print_char(rem + 48, count);
		else
		{
			if (c == 'x')
				count = ft_print_char(rem + 55 + 32, count);
			else
				count = ft_print_char(rem + 55, count);
		}
	}
	return (count);
}

int	ft_print_u(unsigned int nbr, int count)
{
	if (nbr < 0)
	{
		nbr = 4294967296 + nbr;
		count = ft_print_int(nbr, count);
	}
	else
		count = ft_print_int(nbr, count);
	return (count);
}
