/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:19:17 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/10 12:52:23 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	step_inc(t_data a, t_data b, int *step_x, int *step_y)
{
	if (a.x <= b.x)
		*step_x = 1;
	else
		*step_x = -1;
	if (a.y < b.y)
		*step_y = 1;
	else
		*step_y = -1;
}

int	step_y(t_data *a, int dx, int st)
{
	a->y += st;
	return (2 * dx);
}

int	step_x(t_data *a, int dy, int st)
{
	a->x += st;
	return (2 * dy);
}

void	draw_line(t_data a, t_data b, t_data fdf, t_img *img)
{
	int		d[2];
	int		st[2];
	int		sp;
	char	*dst;

	set(&a, &b, fdf, img);
	d[0] = abs(b.x - a.x);
	d[1] = abs(b.y - a.y);
	step_inc(a, b, &st[0], &st[1]);
	sp = 2 * d[1] - d[0];
	while (a.x != b.x || a.y != b.y)
	{
		if (a.x <= 1800 || a.y <= 1000)
		{
			dst = img->addr + (a.y * img->line_lt + a.x * (img->bpp / 8));
			*(unsigned int *)dst = get_color(a, b);
		}
		if (sp > 0)
			sp -= step_y(&a, d[0], st[1]);
		else if (sp <= 0)
			sp += step_x(&a, d[1], st[0]);
	}
}

void	plot(t_data **map, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*map)->map_h)
	{
		x = 0;
		while (x < (*map)->map_w)
		{
			if (y < (*map)->map_h - 1)
				draw_line(map[y][x], map[y + 1][x], **map, img);
			if (x < (*map)->map_w - 1)
				draw_line(map[y][x], map[y][x + 1], **map, img);
			x++;
		}
		y++;
	}
}
