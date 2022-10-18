/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:20:39 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/14 18:30:12 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(t_data a, t_data b)
{
	if (a.color != 0)
		return (a.color);
	else if (a.z == 0 && b.z == 0)
		return (0xffffff);
	else
		return (0x0000ff);
}

void	iso(t_data *a, float ang)
{
	int	x;
	int	y;

	x = a->x;
	y = a->y;
	a->x = (x - y) * cos(ang);
	a->y = (x + y) * sin(ang) - a->z;
}

int	zoom(t_data *a, t_data *b, int ht, int ht_z)
{
	if (ht > 200)
		ht = 2;
	else if (ht <= 200 && ht > 50)
		ht = 5;
	else if (ht <= 50 && ht > 20)
		ht = 10;
	else if (ht <= 20)
		ht = 20;
	a->x *= ht;
	a->y *= ht;
	a->z = ((double)a->z / ht_z) * 1200 / 4;
	b->z = ((double)b->z / ht_z) * 1200 / 4;
	b->x *= ht;
	b->y *= ht;
	return (ht);
}

void	set(t_data *a, t_data *b, t_data fdf, t_img *img)
{
	int	n;
	int	m;
	int	x;
	int	diff;

	diff = (img->max - img->min);
	if (diff == 0)
		diff = 1;
	x = fmax(fdf.map_h, fdf.map_w);
	x = zoom(a, b, x, diff);
	n = abs(2000 - (fdf.map_w * x) + (x * fdf.map_h)) / 2;
	m = abs(1200 - (fdf.map_h * x)) / 2;
	iso(b, 0.523599);
	iso(a, 0.523599);
	a->x += n;
	a->y += m;
	b->x += n;
	b->y += m;
}
