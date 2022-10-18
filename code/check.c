/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:37:05 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/14 13:17:13 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	str_check(char *str)
{
	if (str == NULL)
		ft_error("Given file is empty");
}

void	valid_file(int x)
{
	if (x <= 0)
		ft_error("Given file is not valid");
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit (1);
}
