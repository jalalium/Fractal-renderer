/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:18:13 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 13:19:28 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	bursttwo(t_burst v, double i, double distance)
{
	long double tmp;
	long double tmp2;
	long double tmp3;

	v.x *= 1.5;
	v.y *= 1.5;
	v.x += 1;
	while (i < v.end)
	{
		tmp = v.a * v.x - v.a * v.a * v.x + v.x * v.b * v.b + 2 * v.a *
		v.b * v.y - v.b * v.y;
		tmp2 = v.b * v.x - 2 * v.a * v.x * v.b + v.a * v.y - v.a * v.a *
		v.y + v.b * v.b * v.y;
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

void	populate_two(t_area *z, long double x, long double y, int j)
{
	int			i;
	long double	temp;
	t_burst		out;

	while (j < z->height)
	{
		i = 0;
		while (i < z->wid)
		{
			x = -2 * pow(z->t, -1 * z->i) + z->a + (long double)i /
				(200 * pow(z->t, z->i));
			y = -2 * pow(z->t, -1 * z->i) + z->b +
				(long double)(j + z->offset) / (200 * pow(z->t, z->i));
			out = (t_burst){x, y, 0.5, 0, z->end, z->trap};
			temp = bursttwo(out, 0, 100);
			to_image(z, temp, i, j);
			i++;
		}
		j++;
	}
}

void	*two(void *arg)
{
	t_area *area;

	area = (t_area*)arg;
	populate_two(area, 0, 0, 0);
	return (NULL);
}
