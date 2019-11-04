/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:23:42 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 01:29:13 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	event_blur(t_data *param, int x, int y)
{
	if (x >= 862 && x <= 878 && y >= 480 && y <= 495)
	{
		param->im_str.fil = 1;
		param->im_str.mag = 1;
	}
	if (x >= 903 && x <= 919 && y >= 480 && y <= 495)
	{
		param->im_str.fil = 1;
		param->im_str.mag = 4;
	}
	if (x >= 940 && x <= 960 && y >= 480 && y <= 495)
	{
		param->im_str.fil = 1;
		param->im_str.mag = 8;
	}
	if (x >= 810 && x <= 855 && y >= 591 && y <= 606)
		param->im_str.lock *= -1;
}

void	event_smooth(t_data *param, int x, int y)
{
	if (x >= 862 && x <= 878 && y >= 520 && y <= 535)
	{
		param->im_str.fil = 2;
		param->im_str.mag = 1;
	}
	if (x >= 903 && x <= 919 && y >= 520 && y <= 535)
	{
		param->im_str.fil = 2;
		param->im_str.mag = 2;
	}
	if (x >= 940 && x <= 960 && y >= 520 && y <= 535)
	{
		param->im_str.fil = 2;
		param->im_str.mag = 3;
	}
	if (x >= 810 && x <= 884 && y >= 614 && y <= 635)
		param->im_str.lat = !(param->im_str.lat);
}

void	event_emboss(t_data *param, int x, int y)
{
	if (x >= 862 && x <= 878 && y >= 568 && y <= 582)
	{
		param->im_str.fil = 3;
		param->im_str.mag = 1;
	}
	if (x >= 903 && x <= 919 && y >= 568 && y <= 582)
	{
		param->im_str.fil = 3;
		param->im_str.mag = 4;
	}
	if (x >= 940 && x <= 960 && y >= 568 && y <= 582)
	{
		param->im_str.fil = 3;
		param->im_str.mag = 8;
	}
}

void	event_man(t_data *param, int x, int y)
{
	if (x >= 0 && x <= 220 && y >= 805 && y <= 1012)
	{
		param->im_str.type = 1;
		param->im_str.i = 0;
		param->im_str.end = 50;
		param->im_str.a = 0;
		param->im_str.b = 0;
	}
	if (x >= 220 && x <= 440 && y >= 805 && y <= 1012)
	{
		param->im_str.type = 3;
		param->im_str.i = 0;
		param->im_str.end = 30;
		param->im_str.a = 0;
		param->im_str.b = 0;
		param->im_str.stop = 1;
	}
}
