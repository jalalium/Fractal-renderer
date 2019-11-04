/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:21:01 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 01:21:10 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		deal_key(int key, t_data *param)
{
	t_data in;

	in = *param;
	if (key == 53)
		exit(0);
	if (key == 69)
		param->im_str.stop = 0;
	if (key == 78)
		param->im_str.stop = 1;
	return (0);
}

int		mouse_press(int button, int x, int y, t_data *param)
{
	if (button == 1)
	{
		event_man(param, x, y);
		event_inv(param, x, y);
		event_col_psy(param, x, y);
		event_opt_zoom(param, x, y);
		event_opt_iter(param, x, y);
		event_colors(param, x, y);
		event_blur(param, x, y);
		event_emboss(param, x, y);
		event_smooth(param, x, y);
		event_one(param, x, y);
	}
	if (button == 2)
		event_two(param);
	if (button == 4 && x < 800)
		event_three(param, x, y);
	if (button == 5 && x < 800)
		event_four(param, x, y);
	return (0);
}

int		julia_var(int x, int y, t_data *param)
{
	if (param->im_str.stop == 1)
	{
		param->im_str.jul_x = (double)(x - 400) / (200 * pow(param->im_str.t,
		param->im_str.i));
		param->im_str.jul_y = (double)(y - 400) / (200 * pow(param->im_str.t,
		param->im_str.i));
		mandelbrot(param, -1);
		filter(param);
		mlx_put_image_to_window(param->mlx_ptr, param->mlx_win,
				param->img3, 0, 798);
		mlx_put_image_to_window(param->mlx_ptr, param->mlx_win,
				param->img2, 800, 0);
		write_settings(param);
		mlx_put_image_to_window(param->mlx_ptr, param->mlx_win,
				param->img1, 0, 0);
		param->im_str.stop = (param->im_str.type == 3 ? 1 : 0);
	}
	return (0);
}
