/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:24:05 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 01:28:16 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	event_inv(t_data *param, int x, int y)
{
	if (x >= 440 && x <= 660 && y >= 805 && y <= 1012)
	{
		param->im_str.type = 2;
		param->im_str.i = 0;
		param->im_str.end = 30;
		param->im_str.a = 0;
		param->im_str.b = 0;
	}
	if (x >= 660 && x <= 880 && y >= 805 && y <= 1012)
	{
		param->im_str.type = 4;
		param->im_str.i = 0;
		param->im_str.end = 50;
		param->im_str.a = 0;
		param->im_str.b = 0;
	}
	if (x >= 880 && x <= 1100 && y >= 805 && y <= 1012)
	{
		param->im_str.type = 5;
		param->im_str.i = 0;
		param->im_str.end = 50;
		param->im_str.a = 0;
		param->im_str.b = 0;
	}
}

void	filter(t_data *param)
{
	if (param->im_str.fil == 1)
		blur(param->im_str.ytr, param->im_str.mag);
	if (param->im_str.fil == 2)
		emboss(param->im_str.ytr, param->im_str.mag);
	if (param->im_str.fil == 3)
		smooth(param->im_str.ytr, param->im_str.mag);
}

void	event_one(t_data *param, int x, int y)
{
	x = y;
	mandelbrot(param, -1);
	filter(param);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win,
		param->img3, 0, 798);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win,
		param->img2, 800, 0);
	write_settings(param);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win,
		param->img1, 0, 0);
}

void	event_two(t_data *param)
{
	mandelbrot(param, -1);
	filter(param);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win,
		param->img3, 0, 798);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win,
		param->img2, 800, 0);
	write_settings(param);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->img1, 0, 0);
}
