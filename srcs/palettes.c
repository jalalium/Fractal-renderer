/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:42:57 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 01:06:23 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	pal_blue(double ite, int end)
{
	if (ite < end / 3)
		ite *= 5;
	if (ite >= 8 * end / 9)
		return (229);
	else if (ite >= 7 * end / 9)
		return (204);
	else if (ite >= 6 * end / 9)
		return (178);
	else if (ite >= 5 * end / 9)
		return (153);
	else if (ite >= 4 * end / 9)
		return (127);
	else if (ite >= 3 * end / 9)
		return (102);
	else if (ite >= 2 * end / 9)
		return (76);
	else if (ite >= 1 * end / 9)
		return (51);
	else
		return (25);
}

int	pal_red(double ite, int end)
{
	if (ite < end / 3)
		ite *= 5;
	if (ite >= 4 * end / 9)
		return (255);
	else if (ite >= 3 * end / 9)
		return (204);
	else if (ite >= 2 * end / 9)
		return (153);
	else if (ite >= 1 * end / 9)
		return (102);
	else
		return (51);
}

int	pal_green(double ite, int end)
{
	if (ite < end / 3)
		ite *= 5;
	if (ite >= 8 * end / 9)
		return (204);
	else if (ite >= 7 * end / 9)
		return (153);
	else if (ite >= 6 * end / 9)
		return (102);
	else if (ite >= 5 * end / 9)
		return (51);
	else
		return (0);
}
