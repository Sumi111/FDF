/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:16:25 by sfathima          #+#    #+#             */
/*   Updated: 2022/02/22 17:24:08 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_esc(int key_code, t_data **vars)
{
	int	i;

	i = 0;
	if (key_code == 53)
	{
		mlx_destroy_window((*vars)->mlx, (*vars)->win);
		while (i < (*vars)->map_h)
		{
			free (vars[i]);
			i++;
		}
		free(vars);
		exit (0);
	}
	return (0);
}

int	ft_close_x(t_data **vars)
{
	int	i;

	i = 0;
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	while (i < (*vars)->map_h)
	{
		free (vars[i]);
		i++;
	}
	free(vars);
	exit (0);
}

int	main(int argc, char *argv[])
{
	char	*path;
	t_data	**matrix;
	t_img	img;

	if (argc != 2)
		ft_error("Need 2 arguments: ./fdf map.fdf");
	if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) == NULL)
		ft_error("Try again!!File should have the format : *.fdf");
	path = ft_strjoin("test_maps/", argv[1]);
	matrix = read_map(path, &img);
	free (path);
	(*matrix)->mlx = mlx_init();
	(*matrix)->win = mlx_new_window((*matrix)->mlx, 2000, 1200, "FDF");
	img.img = mlx_new_image((*matrix)->mlx, 2000, 1200);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lt, &img.endian);
	plot(matrix, &img);
	mlx_put_image_to_window((*matrix)->mlx, (*matrix)->win, img.img, 0, 0);
	mlx_hook((*matrix)->win, 02, 0, ft_close_esc, matrix);
	mlx_hook((*matrix)->win, 17, 0, ft_close_x, matrix);
	mlx_loop((*matrix)->mlx);
}
