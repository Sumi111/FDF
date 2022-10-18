/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:17:14 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/16 11:22:39 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_max(int z)
{
	static int	max;

	if (z >= max)
		max = z;
	return (max);
}

int	get_min(int z)
{
	static int	min;

	if (z < min)
		min = z;
	return (min);
}

int	get_pts(char *ln, t_data **matrix, int j, t_img *img)
{
	int		i;
	char	**m;
	char	*str;

	i = 0;
	m = ft_split(ln, ' ');
	while (m[i] != NULL)
	{
		matrix[j][i].z = ft_atoi(m[i]);
		img->max = get_max(matrix[j][i].z);
		img->min = get_min(matrix[j][i].z);
		str = ft_strchr(m[i], ',');
		matrix[j][i].color = ft_atoi_h(str);
		matrix[j][i].x = i;
		matrix[j][i].y = j;
		free (m[i]);
		i++;
	}
	free (m[i]);
	return (i);
}

t_data	**allo_mem(char *path)
{
	t_data	**mat;
	char	*str;
	int		x[2];
	int		fd;

	x[0] = 0;
	x[1] = 0;
	fd = open(path, O_RDONLY);
	valid_file(fd);
	str = get_next_line(fd);
	str_check(str);
	x[0] = ft_word_count(str, ' ');
	valid_file(x[0]);
	while (str)
	{
		free (str);
		str = get_next_line(fd);
		x[1]++;
	}
	mat = malloc(sizeof(t_data *) * (x[1]));
	while (x[1] > 0)
		mat[--x[1]] = malloc(sizeof(t_data) * (x[0]));
	close (fd);
	return (mat);
}

t_data	**read_map(char *path, t_img *img)
{
	t_data	**mat;
	char	*ln;
	int		row;
	int		col;
	int		fd;

	row = 0;
	col = 0;
	ln = NULL;
	mat = allo_mem(path);
	fd = open(path, O_RDONLY);
	while (ln || row == 0)
	{
		ln = get_next_line(fd);
		if (ln != NULL)
		{
			col = get_pts(ln, mat, row++, img);
			free(ln);
		}
	}
	(*mat)->map_w = col;
	(*mat)->map_h = row;
	close(fd);
	return (mat);
}
