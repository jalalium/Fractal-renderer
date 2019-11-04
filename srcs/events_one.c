/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:22:54 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 01:23:17 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	event_opt_zoom(t_data *param, int x, int y)
{
	if (x >= 815 && x <= 845 && y >= 82 && y <= 95 && param->im_str.i == 0)
		param->im_str.t = 1.2;
	if (x >= 875 && x <= 905 && y >= 82 && y <= 95 && param->im_str.i == 0)
		param->im_str.t = 1.5;
	if (x >= 936 && x <= 970 && y >= 82 && y <= 95 && param->im_str.i == 0)
		param->im_str.t = 1.6;
	if (x >= 993 && x <= 1025 && y >= 82 && y <= 95 && param->im_str.i == 0)
		param->im_str.t = 1.8;
	if (x >= 1052 && x <= 1069 && y >= 82 && y <= 95 && param->im_str.i == 0)
		param->im_str.t = 2;
}

void	event_col_psy(t_data *param, int x, int y)
{
	if (x >= 992 && x <= 1000 && y >= 250 && y <= 260)
		param->im_str.red += 0.1;
	if (x >= 1052 && x <= 1058 && y >= 250 && y <= 260)
		param->im_str.red -= 0.1;
	if (x >= 992 && x <= 1000 && y >= 270 && y <= 280)
		param->im_str.blue += 3;
	if (x >= 1052 && x <= 1057 && y >= 270 && y <= 280)
		param->im_str.blue -= 3;
	if (x >= 992 && x <= 1000 && y >= 290 && y <= 300)
		param->im_str.red += 0.1;
	if (x >= 1052 && x <= 1058 && y >= 290 && y <= 300)
		param->im_str.red -= 0.1;
	if (x >= 810 && x <= 950 && y >= 358 && y <= 370)
		param->im_str.trap += 1;
}

void	event_opt_iter(t_data *param, int x, int y)
{
	if (x >= 810 && x <= 840 && y >= 150 && y <= 170)
		param->im_str.end += 10;
	if (x >= 860 && x <= 890 && y >= 150 && y <= 170)
		param->im_str.end += 20;
	if (x >= 910 && x <= 940 && y >= 150 && y <= 170)
		param->im_str.end += 50;
	if (x >= 960 && x <= 1000 && y >= 150 && y <= 170)
		param->im_str.end += 100;
	if (x >= 1020 && x <= 1060 && y >= 150 && y <= 170)
		param->im_str.end += 200;
	if (x >= 810 && x <= 840 && y >= 180 && y <= 195 && param->im_str.end > 20)
		param->im_str.end -= 10;
	if (x >= 860 && x <= 890 && y >= 180 && y <= 195 && param->im_str.end > 40)
		param->im_str.end -= 20;
	if (x >= 910 && x <= 940 && y >= 180 && y <= 195 && param->im_str.end > 70)
		param->im_str.end -= 50;
	if (x >= 960 && x <= 1000 && y >= 180 && y <= 195 &&
		param->im_str.end > 160)
		param->im_str.end -= 100;
	if (x >= 1020 && x <= 1060 && y >= 180 && y <= 195 &&
		param->im_str.end > 280)
		param->im_str.end -= 200;
}

void	event_colors(t_data *param, int x, int y)
{
	if (x >= 810 && x <= 927 && y >= 227 && y <= 239)
	{
		param->im_str.c = 0;
		param->im_str.trap = 0;
	}
	if (x >= 810 && x <= 968 && y >= 312 && y <= 327)
	{
		param->im_str.c = 1;
		param->im_str.trap = 0;
	}
	if (x >= 810 && x <= 858 && y >= 336 && y <= 348)
	{
		param->im_str.c = 2;
		param->im_str.trap = 0;
	}
}
