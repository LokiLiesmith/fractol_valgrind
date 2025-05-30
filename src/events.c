/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:44:19 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/23 12:34:29 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		close_handler(fractal);
		return (0);
	}
	else if (keycode == 126)
		fractal->offset_y += (0.5 * fractal->zoom);
	else if (keycode == 125)
		fractal->offset_y -= (0.5 * fractal->zoom);
	else if (keycode == 124)
		fractal->offset_x -= (0.5 * fractal->zoom);
	else if (keycode == 123)
		fractal->offset_x += (0.5 * fractal->zoom);
	else if (keycode == 69)
		fractal->max_i += 10;
	else if (keycode == 78)
		fractal->max_i -= 10;
	ft_render(fractal);
	return (1);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	ft_printf("x:%d | y:%d\nbutton: %d\n", x, y, button);
	ft_printf("x:%d | y:%d\n", x, y);
	if (button == 5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == 4)
		fractal->zoom *= 1.05;
	ft_render(fractal);
	return (0);
}

#ifdef __linux__

void	free_linux(t_fractal *fractal)
{
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
}
#else

void	free_linux(t_fractal *fractal)
{
	(void)fractal;
}
#endif

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free_linux(fractal);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
