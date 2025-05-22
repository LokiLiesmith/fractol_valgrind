/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:17:37 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/22 11:19:59 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	interpolate_gradient(unsigned int s, unsigned int e, float t)
{
	unsigned int	result;
	t_argb			c;

	c.sr = (s >> 16) & 0xFF;
	c.sg = (s >> 8) & 0xFF;
	c.sb = (s >> 0) & 0xFF;
	c.er = (e >> 16) & 0xFF;
	c.eg = (e >> 8) & 0xFF;
	c.eb = (e >> 0) & 0xFF;
	c.r = c.sr + (int)((c.er - c.sr) * t);
	c.g = c.sg + (int)((c.eg - c.sg) * t);
	c.b = c.sb + (int)((c.eb - c.sb) * t);
	result = (c.r << 16) | (c.g << 8) | c.b;
	return (result);
}

void	ft_put_pixel_to_image(t_fractal *fractal)
{
	int		bytes_per_pixel;
	char	*row_start;
	char	*pixel_addr;

	bytes_per_pixel = fractal->bits_per_pixel / 8;
	row_start = fractal->ptr_to_img + (fractal->y * fractal->line_length);
	pixel_addr = row_start + (fractal->x * bytes_per_pixel);
	*(unsigned int *)pixel_addr = fractal->color;
}

// unsigned int	add_shade(int color, float t)
// {
// 	if (t <= 0.0)
// 		return (color);
// 	if (t >= 1.0)
// 		return (0x00000000);

// 	float factor = 1.0 - t;

// 	int a = (color >> 24) & 0xFF;
// 	int r = (color >> 16) & 0xFF;
// 	int g = (color >> 8) & 0xFF;
// 	int b = (color >> 0) & 0xFF;

// 	r = (unsigned int)r * factor;
// 	g = (unsigned int)g * factor;
// 	b = (unsigned int)b * factor;
// 	return ((a << 24) | (r << 16) | (g << 8) | b);
// }

/* unsigned int	interpolate_gradient(unsigned int s, unsigned int e, float t)
{
	unsigned int	result;
	t_argb			c;

	// c.sa = (s >> 24) & 0xFF;
	c.sr = (s >> 16) & 0xFF;
	c.sg = (s >> 8) & 0xFF;
	c.sb = (s >> 0) & 0xFF;
	// c.ea = (e >> 24) & 0xFF;
	c.er = (e >> 16) & 0xFF;
	c.eg = (e >> 8) & 0xFF;
	c.eb = (e >> 0) & 0xFF;
	// c.a = c.sa + (int)((c.ea - c.sa) * t);
	c.r = c.sr + (int)((c.er - c.sr) * t);
	c.g = c.sg + (int)((c.eg - c.sg) * t);
	c.b = c.sb + (int)((c.eb - c.sb) * t);
	// result = (c.a << 24) | (c.r << 16) | (c.g << 8) | c.b;
	result = (c.r << 16) | (c.g << 8) | c.b;
	return (result);
} */