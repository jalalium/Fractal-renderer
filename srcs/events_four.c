/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:24:38 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 15:34:54 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	todo(t_data *g)
{
	mandelbrot(g, -1);
	filter(g);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->img3, 0, 798);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->img2, 800, 0);
	write_settings(g);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->img1, 0, 0);
}

void	event_three(t_data *g, int x, int y)
{
	(g->im_str).i++;
	if (g->im_str.lock == -1)
		(g->im_str).fil = 0;
	(g->im_str).end += g->im_str.t < 1.5 ? 1 : 2;
	if ((g->im_str).i > 0)
	{
		g->im_str.a = -2 * pow(g->im_str.t, -1 * (g->im_str).i + 1) +
g->im_str.a + (long double)(x) / (200 * pow(g->im_str.t, (g->im_str).i - 1));
		g->im_str.b = -2 * pow(g->im_str.t, -1 * (g->im_str).i + 1) +
g->im_str.b + (long double)(y) / (200 * pow(g->im_str.t, (g->im_str).i - 1));
		g->im_str.a -= (double)(x - 400) / (200 * pow(g->im_str.t,
g->im_str.i));
		g->im_str.b -= (double)(y - 400) / (200 * pow(g->im_str.t,
g->im_str.i));
	}
	todo(g);
}

void	event_four(t_data *g, int x, int y)
{
	if (g->im_str.lock == -1)
		(g->im_str).fil = 0;
	if (g->im_str.i > 0)
	{
		(g->im_str).i--;
		(g->im_str).end -= (g->im_str.t > 1.5 ? 2 : 1);
	}
	else
	{
		g->im_str.a = 0;
		g->im_str.b = 0;
	}
	if ((g->im_str).i > 0)
	{
		g->im_str.a = 2 * pow(g->im_str.t, -1 * (g->im_str).i) +
g->im_str.a - (double)(x) / (200 * pow(g->im_str.t, (g->im_str).i));
		g->im_str.b = 2 * pow(g->im_str.t, -1 * (g->im_str).i) +
g->im_str.b - (double)(y) / (200 * pow(g->im_str.t, (g->im_str).i));
		g->im_str.a += (double)(x - 400) / (200 * pow(g->im_str.t,
g->im_str.i + 1));
		g->im_str.b += (double)(y - 400) / (200 * pow(g->im_str.t,
g->im_str.i + 1));
	}
	todo(g);
}
