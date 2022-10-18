/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utlis_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:15:57 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/02 11:14:27 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_print_str(char *str, int count)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		count += ft_strlen(str);
	}
	else
	{
		count = ft_print_str("(null)", count);
	}
	return (count);
}

int	ft_print_ptr(unsigned long long pt, int count)
{
	count = ft_print_str("0x", count);
	if (pt == 0)
		count = ft_print_char('0', count);
	else
		count = ft_print_ptrhex(pt, count);
	return (count);
}

int	ft_print_ptrhex(unsigned long long nbr, int count)
{
	unsigned long int	rem;

	rem = 0;
	if (nbr)
	{
		rem = nbr % 16;
		count = ft_print_ptrhex(nbr / 16, count);
		if (rem < 10)
			count = ft_print_char(rem + 48, count);
		else
			count = ft_print_char(rem + 55 + 32, count);
	}
	return (count);
}
