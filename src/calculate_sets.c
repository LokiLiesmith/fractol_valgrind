/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_sets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:41:59 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/22 15:33:00 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calculate_mandelbrot(t_fractal *f)
{
	int		i;
	double	tmp_x;
	float	t;

	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (map(&f->range_x, &f->new_range_x, f->x) * f->zoom) + f->offset_x;
	f->cy = (map(&f->range_y, &f->new_range_y, f->y) * f->zoom) + f->offset_y;
	while ((f->zx * f->zx) + (f->zy * f->zy) <= f->escape_r_sqr && i < f->max_i)
	{
		tmp_x = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = 2.0 * f->zx * f->zy + f->cy;
		f->zx = tmp_x;
		i++;
	}
	if (i == f->max_i)
		f->color = 0x000000;
	else
	{
		t = (float)i / (float)f->max_i;
		f->color = interpolate_gradient(BLACK, L_GREEN, t) * i;
	}
	ft_put_pixel_to_image(f);
}

void	default_julia_check(t_fractal *f)
{
	if (!f->cx)
		f->cx = 0.285;
	if (!f->cy)
		f->cy = 0.001;
}

void	ft_calculate_julia(t_fractal *f)
{
	int		i;
	double	tmp_x;
	float	t;

	i = 0;
	default_julia_check(f);

	f->zx = (map(&f->range_x, &f->new_range_x, f->x) * f->zoom) + f->offset_x;
	f->zy = (map(&f->range_y, &f->new_range_y, f->y) * f->zoom) + f->offset_y;
	while ((f->zx * f->zx) + (f->zy * f->zy) <= f->escape_r_sqr && i < f->max_i)
	{
		tmp_x = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = 2.0 * f->zx * f->zy + f->cy;
		f->zx = tmp_x;
		i++;
	}
	if (i == f->max_i)
		f->color = 0x000000;
	else
	{
		t = (float)i / (float)f->max_i;
		f->color = interpolate_gradient(BLACK, L_GREEN, t) * i;
	}
	ft_put_pixel_to_image(f);
}

void	ft_calculate_ship(t_fractal *f)
{
	int		i;
	double	tmp_x;
	float	t;

	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (map(&f->range_x, &f->new_range_x, f->x) * f->zoom) + f->offset_x;
	f->cy = (map(&f->range_y, &f->new_range_y, f->y) * f->zoom) + f->offset_y;
	while ((f->zx * f->zx) + (f->zy * f->zy) <= f->escape_r_sqr && i < f->max_i)
	{
		tmp_x = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = fabs(2.0 * f->zx * f->zy) + f->cy;
		f->zx = tmp_x;
		i++;
	}
	if (i == f->max_i)
		f->color = 0x000000;
	else
	{
		t = (float)i / (float)f->max_i;
		f->color = interpolate_gradient(BLACK, L_GREEN, t) * i;
	}
	ft_put_pixel_to_image(f);
}
