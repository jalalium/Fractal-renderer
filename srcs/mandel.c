/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 23:02:44 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 01:15:00 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	burstm(t_burst v, double i, double di)
{
	long double tmp;
	long double tmp2;
	long double tmp3;

	while (i < v.end)
	{
		tmp = v.a * v.a + v.x - v.b * v.b;
		tmp2 = 2 * v.a * v.b + v.y;
		tmp3 = tmp * tmp + tmp2 * tmp2;
		if (tmp3 < di)
			di = tmp3;
		if (tmp3 >= 4)
			return (i * (1 + v.trap * pow(di, 1 + 0.1 * v.trap)));
		else
		{
			v.a = tmp;
			v.b = tmp2;
		}
		i++;
	}
	return (i * (1 + v.trap * pow(di, 1 + 0.1 * v.trap)));
}

void	populate_man(t_area *z, long double x, long double y, int j)
{
	int			i;
	long double	temp;
	t_burst		out;

	while (j < z->height)
	{
		i = 0;
		while (i < z->wid)
		{
			x = -2 * pow(z->t, -1 * z->i) + z->a +
			(long double)i / (200 * pow(z->t, z->i));
			y = -2 * pow(z->t, -1 * z->i) + z->b +
			(long double)(j + z->offset) / (200 * pow(z->t, z->i));
			out = (t_burst){x, y, 0, 0, z->end, z->trap};
			temp = burstm(out, 0, 100);
			to_image(z, temp, i, j);
			i++;
		}
		j++;
	}
}

void	*man(void *arg)
{
	t_area *area;

	area = (t_area*)arg;
	populate_man(area, 0, 0, 0);
	return (NULL);
}
