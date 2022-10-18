/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:41:19 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/03 12:12:26 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_h(const char *str)
{
	unsigned long	n;

	n = 0;
	if (str == NULL)
		return (0);
	while (((*str >= 9) && (*str <= 13)) || (*str == ' ') || (*str == ','))
		str++;
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
	{
		str++;
		str++;
	}
	while (*str)
	{
		if ((*str >= '0') && (*str <= '9'))
			n = (n * 16) + (*str - '0' + 0);
		else if ((*str >= 'A') && (*str <= 'F'))
			n = (n * 16) + (*str - 'A' + 10);
		else if ((*str >= 'a') && (*str <= 'f'))
			n = (n * 16) + (*str - 'a' + 10);
		else
			break ;
		str++;
	}
	return (n);
}
