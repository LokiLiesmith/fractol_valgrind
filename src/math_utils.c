/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:17:19 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/23 12:34:43 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(t_range *old_range, t_range *new_range, double point)
{
	double	f;

	f = (point - old_range->min) / (old_range->max - old_range->min);
	return ((new_range->max - new_range->min) * f + new_range->min);
}
