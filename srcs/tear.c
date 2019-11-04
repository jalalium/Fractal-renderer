/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tear.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 23:00:25 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 01:14:32 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	burstt(t_burst v, double i, double distance)
{
	long double tmp;
	long double tmp2;
	long double tmp3;

	tmp3 = ((1.32 * v.x + 1.3) * (1.32 * v.x + 1.3) + 1.7424 * v.y * v.y);
	tmp = (1.32 * v.x + 1.3) / tmp3;
	tmp2 = -1 * (1.32 * v.y) / tmp3;
	v.x = tmp;
	v.y = tmp2;
	while (i < v.end)
	{
		tmp = v.a * v.a + v.x - v.b * v.b;
		tmp2 = 2 * v.a * v.b + v.y;
		tmp3 = tmp * tmp + tmp2 * tmp2;
		if (tmp3 < distance)
			distance = tmp3;
		if (tmp3 >= 4)
			return (i * (1 + v.trap * pow(distance, 1 + 0.1 * v.trap)));
		v.a = tmp;
		v.b = tmp2;
		i++;
	}
	return (i * (1 + v.trap * pow(distance, 1 + 0.1 * v.trap)));
}

void	to_image(t_area *z, long double temp, int i, int j)
{
	unsigned char *str;

	str = *(z->str);
	str[4 * (i + z->wid * j)] = col_blue(temp, z->end, z->blue, z->col);
	str[4 * (i + z->wid * j) + 1] = col_green(temp, z->end, z->green, z->col);
	str[4 * (i + z->wid * j) + 2] = col_red(temp, z->end, z->red, z->col);
	str[4 * (i + z->wid * j) + 3] = z->lat;
}

void	populate_tear(t_area *z, long double x, long double y, int j)
{
	int			i;
	long double	temp;
	t_burst		out;

	while (j < z->height)
	{
		i = 0;
		while (i < z->wid)
		{
			x = -2 * pow(z->t, -1 * z->i) + z->a + (double)i /
				(200 * pow(z->t, z->i));
			y = -2 * pow(z->t, -1 * z->i) + z->b + (double)(j + z->offset)
				/ (200 * pow(z->t, z->i));
			out = (t_burst){x, y, 0, 0, z->end, z->trap};
			temp = burstt(out, 0, 100);
			to_image(z, temp, i, j);
			i++;
		}
		j++;
	}
}

void	*tear(void *arg)
{
	t_area *area;

	area = (t_area*)arg;
	populate_tear(area, 0, 0, 0);
	return (NULL);
}
