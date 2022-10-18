/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:46:35 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/02 11:12:00 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_args(char c, va_list ap, int ct)
{
	if (c == 'c')
		ct = ft_print_char(va_arg(ap, int), ct);
	else if (c == 's')
		ct = ft_print_str(va_arg(ap, char *), ct);
	else if (c == 'p')
		ct = ft_print_ptr(va_arg(ap, unsigned long long), ct);
	else if ((c == 'd') || (c == 'i'))
		ct = ft_print_int(va_arg(ap, int), ct);
	else if (c == 'u')
		ct = ft_print_u(va_arg(ap, unsigned int), ct);
	else if ((c == 'x') || (c == 'X'))
		ct = ft_check_hex(va_arg(ap, unsigned int), ct, c);
	return (ct);
}

int	ft_arg_sharp(char c, va_list ap, int ct)
{
	int	x;

	x = 0;
	x = va_arg(ap, unsigned int);
	if (x == 0)
	{
		ct = ft_print_char('0', ct);
		return (ct);
	}
	else
	{
		if (c == 'x')
		{
			ct = ft_print_str("0x", ct);
			ct = ft_check_hex(x, ct, c);
		}
		else
		{
			ct = ft_print_str("0X", ct);
			ct = ft_check_hex(x, ct, c);
		}
	}
	return (ct);
}

int	ft_arg_bonus(char c, va_list ap, int ct, char d)
{
	if (c == '#')
		ct = ft_arg_sharp(d, ap, ct);
	else if (c == '+')
		ct = ft_arg_plus(ap, ct, c);
	else if (c == ' ' || ft_isdigit(c))
		ct = ft_arg_space(ap, ct, c, d);
	return (ct);
}

int	ft_check(char c, va_list ap, int ct)
{
	if (ft_isalpha(c))
		ct = ft_args(c, ap, ct);
	else if (c == '%')
		ct = ft_print_char('%', ct);
	return (ct);
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	va_start(ap, arg);
	while (arg[i])
	{
		if (arg[i] != '%')
			ct = ft_print_char(arg[i], ct);
		else if (arg[i] == '%')
		{
			ct = ft_check(arg[++i], ap, ct);
			while (arg[i] == ' ' || arg[i] == '+' || arg[i] == '#')
				i++;
			if (ft_isdigit(arg[i]))
				i = i + 1;
			ct = ft_arg_bonus(arg [i - 1], ap, ct, arg[i]);
		}
		i++;
	}
	va_end(ap);
	return (ct);
}
