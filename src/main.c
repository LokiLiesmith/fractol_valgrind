/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:16:07 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/23 12:34:41 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	input_checker(int argc, char *input)
{
	if (argc == 2 && !ft_strncmp(input, "mandelbrot", 10))
		return (1);
	else if (argc == 2 && !ft_strncmp(input, "ship", 4))
		return (1);
	else if (argc == 4 && !ft_strncmp(input, "julia", 5))
		return (1);
	return (0);
}

int	ft_render(t_fractal *fractal)
{
	if (ft_strncmp(fractal->fractal_set, "mandelbrot", 10) == 0)
		ft_render_mandelbrot(fractal);
	else if (ft_strncmp(fractal->fractal_set, "julia", 5) == 0)
		ft_render_julia(fractal);
	else if (ft_strncmp(fractal->fractal_set, "ship", 4) == 0)
		ft_render_ship(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (input_checker(argc, argv[1]))
	{
		fractal.fractal_set = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractal.cx = atodbl(argv[2]);
			fractal.cy = atodbl(argv[3]);
		}
		init_fractal(&fractal);
		init_mlx(&fractal);
		ft_render(&fractal);
		mlx_key_hook(fractal.win, key_handler, &fractal);
		mlx_hook(fractal.win, 4, (1L << 2), mouse_handler, &fractal);
		mlx_hook(fractal.win, 17, 0, close_handler, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_printf(ERROR_MESSAGE);
		exit(EXIT_SUCCESS);
		return (EXIT_SUCCESS);
	}
}
