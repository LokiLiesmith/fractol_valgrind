/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:33:02 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/22 16:38:45 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_fail(void)
{
	perror("Malloc Fail");
	exit(1);
}

static	void	clean_ptr_to_img(t_fractal *fractal)
{
	if (fractal->ptr_to_img == NULL)
	{
		mlx_destroy_image(fractal->mlx, fractal->img);
		mlx_destroy_window(fractal->mlx, fractal->win);
		free(fractal->mlx);
		malloc_fail();
	}

}


void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		malloc_fail();
	fractal->win = mlx_new_window(fractal->mlx, WIN_W, WIN_H, "Fract-ol");
	if (fractal->win == NULL)
	{
		free(fractal->mlx);
		malloc_fail();
	}
	fractal->img = mlx_new_image(fractal->mlx, WIN_W, WIN_H);
	if (fractal->img == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		free(fractal->mlx);
		malloc_fail();
	}
	fractal->ptr_to_img = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel,
			&fractal->line_length,
			&fractal->endian);
	clean_ptr_to_img(fractal);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->zoom = 1;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->max_i = 100;
	fractal->new_range_x.max = 2;
	fractal->new_range_x.min = -2;
	fractal->new_range_y.max = 2;
	fractal->new_range_y.min = -2;
	fractal->range_x.max = WIN_W;
	fractal->range_x.min = 0;
	fractal->range_y.max = WIN_H;
	fractal->range_y.min = 0;
	fractal->escape_r_sqr = 4;
}
