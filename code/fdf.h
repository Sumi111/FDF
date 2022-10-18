/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:17:58 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/16 11:22:22 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		z;
	int		map_w;
	int		map_h;
	int		color;
}			t_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lt;
	int		endian;
	int		max;
	int		min;
}				t_img;

void	plot(t_data **map, t_img *img);
t_data	**read_map(char *path, t_img *img);
t_data	**allo_mem(char *path);
int		get_pts(char *ln, t_data **matrix, int j, t_img *img);
void	draw_line(t_data a, t_data b, t_data fdf, t_img *img);
int		zoom(t_data *a, t_data *b, int ht, int ht_z);
void	iso(t_data *a, float ang);
int		get_color(t_data a, t_data b);
void	set(t_data *a, t_data *b, t_data map, t_img *img);
void	ft_error(char *str);
int		ft_close_x(t_data **vars);
int		ft_close_esc(int key_code, t_data **vars);
void	str_check(char *str);
void	valid_file(int x);

#endif