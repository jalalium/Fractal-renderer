/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:17:30 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/03 19:44:29 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	col_blue(double ite, int end, double blue, int c)
{
	if (c == 0)
	{
		if (ite == end)
			return (0);
		if (ite == 0)
			return (0);
		return (ite * blue);
	}
	else if (c == 1)
	{
		if (ite == end)
			return (255);
		return (ite == end ? ite * 3 : ite * ite * 3);
	}
	else if (c == 2)
		return (pal_blue(ite, end));
	else
		return (0);
}

int	col_red(double ite, int end, double red, int c)
{
	if (c == 0)
	{
		if (ite == end)
			return (0);
		if (ite == 0)
			return (0);
		return (128 + 127 * cos(red * ite));
	}
	else if (c == 1)
	{
		if (ite == end)
			return (255);
		return (ite == end ? ite * 3 : ite * ite * 3);
	}
	else if (c == 2)
		return (pal_red(ite, end));
	else
		return (0);
}

int	col_green(double ite, int end, double green, int c)
{
	if (c == 0)
	{
		if (ite == end)
			return (0);
		if (ite == 0)
			return (0);
		return (128 + 127 * sin(green * ite));
	}
	else if (c == 1)
	{
		if (ite == end)
			return (255);
		return (ite == end ? ite * 3 : ite * ite * 3);
	}
	else if (c == 2)
		return (pal_green(ite, end));
	else
		return (0);
}
