/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:19:34 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/22 15:25:43 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../include/minilibx/mlx.h"
# include "../include/libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIN_H 1000
# define WIN_W 1000
# define EXIT_SUCCESS 0
# define ERROR_MESSAGE "Available fractals: mandelbrot, julia, ship\n\
Use like this: ./fractol <fractal name>\nfor specific julia start: ./frac\
tol <fractal name> <value 1> <value 2>\n"

# define EL_BLUE 0x1BE7FF
# define L_GREEN 0x6EEB83
# define LEMON_LIME 0xE4FF1A
# define SEL_YELLOW 0xFFB800
# define GIANTS_ORANGE 0xFF5714
# define BLACK 0x000000
# define WHITE 0xFFFFFF

// RANGE STRUCT FOR INTERPOLATION
typedef struct s_range
{
	double	max;
	double	min;
}			t_range;

typedef struct s_argb
{
	int	sa;
	int	sr;
	int	sg;
	int	sb;
	int	ea;
	int	er;
	int	eg;
	int	eb;
	int	a;
	int	r;
	int	g;
	int	b;
}	t_argb;

typedef struct s_atodobl
{
	double	sign;
	double	result;
	double	factor;

}			t_atodobl;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*ptr_to_img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		color;
	double	zx;//real component of z
	double	zy;//imaginary component of z
	double	cx;//x coordinate after transforms
	double	cy;//y coord 
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	escape_r_sqr;
	char	*fractal_set;
	int		max_i;
	t_range	new_range_x;
	t_range	new_range_y;
	t_range	range_x;
	t_range	range_y;
}			t_fractal;

//init.c
void			init_mlx(t_fractal *fractal);
void			init_fractal(t_fractal *fractal);
t_range			*init_range(void);

//event_listeners.c
int				key_handler(int keycode, t_fractal *fractal);
int				mouse_handler(int mouse_code, int x, int y, t_fractal *fractal);

// render.c
int				ft_render(t_fractal *fractal);
int				ft_render_mandelbrot(t_fractal *fractal);
int				ft_render_julia(t_fractal *fractal);
int				ft_render_ship(t_fractal *fractal);
// int			ft_render_nova(t_fractal *fractal);

// render_utils.c
void			ft_put_pixel_to_image(t_fractal *fractal);
unsigned int	interpolate_gradient(unsigned int s, unsigned int e, float t);
unsigned int	add_shade(int color, float t);

void			ft_calculate_mandelbrot(t_fractal *fractal);
void			ft_calculate_julia(t_fractal *j);
void			ft_calculate_ship(t_fractal *s);
void			default_julia_check(t_fractal *f);

// void			ft_calculate_nova(t_fractal *n);

//math_utils.c
double			map(t_range *old_range, t_range *new_range, double point);
//string_utils.c
double			atodbl(const char *str);

//cleanup
int				close_handler(t_fractal *fractal);

#endif
