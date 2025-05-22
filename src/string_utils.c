/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:41:46 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/22 13:00:37 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

double	atodbl(const char *str)
{
	t_atodobl	n;

	n.sign = 1.0;
	n.result = 0.0;
	n.factor = 1.0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n.sign = -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		n.result = n.result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			n.result = n.result * 10.0 + (*str++ - '0');
			n.factor = n.factor * 10.0;
		}
	}
	return (n.sign * (n.result / n.factor));
}
