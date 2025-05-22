/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:32:00 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/21 12:32:07 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

int	ft_render_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->y < WIN_H)
	{
		fractal->x = 0;
		while (fractal->x < WIN_W)
		{
			ft_calculate_mandelbrot(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	ft_printf("inside ft_render_mandelbrot: %s.\n", fractal->fractal_set);
	return (0);
}

int	ft_render_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->y < WIN_H)
	{
		fractal->x = 0;
		while (fractal->x < WIN_W)
		{
			ft_calculate_julia(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	ft_printf("inside ft_draw_julia: %s.\n", fractal->fractal_set);
	return (0);
}

int	ft_render_ship(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->y < WIN_H)
	{
		fractal->x = 0;
		while (fractal->x < WIN_W)
		{
			ft_calculate_ship(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	ft_printf("inside ft_draw_nova: %s.\n", fractal->fractal_set);
	return (0);
}

// int	ft_render_nova(t_fractal *fractal)
// {
// 	fractal->x = 0;
// 	fractal->y = 0;

// 	while (fractal->y < WIN_H)
// 	{
// 		fractal->x = 0;
// 		while (fractal->x < WIN_W)
// 		{
// 			ft_calculate_nova(fractal);
// 			fractal->x++;
// 		}
// 		fractal->y++;
// 	} 
// 	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
// 	ft_printf("inside ft_draw_nova: %s.\n", fractal->fractal_set);
// 	return (0);
// }