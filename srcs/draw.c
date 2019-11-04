/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:20:20 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 13:36:07 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	assemble(unsigned char **ptr, unsigned char **str)
{
	unsigned char	*pt;
	unsigned char	*st;
	int				i;
	int				j;

	pt = *ptr;
	j = 0;
	while (j < 10)
	{
		st = str[j];
		i = 0;
		while (i < 800 * 80 * 4)
		{
			pt[i + 800 * 4 * 80 * j] = st[i];
			i++;
		}
		j++;
	}
	i = -1;
	while (++i < 10)
		free(str[i]);
	free(str);
}

void	mandelbrot(t_data *p, int i)
{
	t_area			*area;
	unsigned char	**sthr;
	pthread_t		tids[10];
	pthread_attr_t	attr;

	area = malloc(sizeof(t_area) * 10);
	sthr = malloc(sizeof(unsigned char*) * 10);
	while (++i < 10)
	{
		sthr[i] = malloc(sizeof(unsigned char) * 800 * 80 * 4);
		area[i] = (t_area){&sthr[i], 80 * i, p->im_str.blue, p->im_str.red,
	p->im_str.green, p->im_str.end, p->im_str.i, p->im_str.a,
	p->im_str.b, p->im_str.t, p->im_str.wid, p->im_str.height,
	p->im_str.jul_x, p->im_str.jul_y, p->im_str.type, p->im_str.c,
	p->im_str.trap, p->im_str.lat};
	}
	pthread_attr_init(&attr);
	i = -1;
	while (++i < 10)
		pthread_create(&tids[i], &attr, draw_frac, &area[i]);
	i = -1;
	while (++i < 10)
		pthread_join(tids[i], NULL);
	assemble(p->im_str.ytr, sthr);
}

void	*draw_frac(void *arg)
{
	if (((t_area*)arg)->type == 3)
		return (julia(arg));
	else if (((t_area*)arg)->type == 2)
		return (inv_man(arg));
	else if (((t_area*)arg)->type == 1)
		return (man(arg));
	else if (((t_area*)arg)->type == 4)
		return (tear(arg));
	else if (((t_area*)arg)->type == 5)
		return (two(arg));
	else
		return (NULL);
}
