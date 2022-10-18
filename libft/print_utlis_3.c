/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utlis_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:44:15 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/08 15:47:46 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_arg_plus(va_list ap, int ct, char c)
{
	int	x;

	x = va_arg(ap, int);
	if (x < 0)
	{
		ct = ft_print_int(x, ct);
		return (ct);
	}
	else if (c == '+')
		ct = ft_print_char('+', ct);
	else
		ct = ft_print_char(' ', ct);
	ct = ft_print_int(x, ct);
	return (ct);
}

int	ft_arg_space(va_list ap, int ct, char c, char d)
{
	if (d == 'd' || d == 'i')
		ct = ft_arg_plus(ap, ct, c);
	else if (d == 's' && !(ft_isdigit(c)))
		ct = ft_print_str(va_arg(ap, char *), ct);
	else
		ct = ft_print_char(' ', ct);
	return (ct);
}
