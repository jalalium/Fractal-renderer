/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 00:07:19 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 00:08:23 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	write_settings_one(t_data *param)
{
	mlx_string_put(param->mlx_ptr, param->mlx_win, 860, 243, 16753920,
			"tweek red:   +     -");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 860, 261, 16753920,
			"tweek blue:  +     -");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 860, 279, 16753920,
			"tweek green: +     -");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 305, 0,
			"Black and White:");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 330, 0, "Pink:");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 350, 0,
			"Trap coloring:");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 450, 0, "Blur:");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 860, 473, 0, "x1  x2  x3");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 491, 0, "Emboss:");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 860, 514, 0, "x1  x2  x3");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 537, 0, "Smoothen:");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 860, 560, 0, "x1  x2  x3");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 813, 583, 0, "Lock:");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 863, 585, 0,
			ft_itoa(param->im_str.lock));
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 610, 0, "Latency:");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 890, 610, 0,
			ft_itoa(param->im_str.lat));
}

void	write_settings_two(t_data *param)
{
	mlx_string_put(param->mlx_ptr, param->mlx_win, 812, 52, 0, "zoom :");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 872, 52, 0,
		ft_itoa(param->im_str.i));
	mlx_string_put(param->mlx_ptr, param->mlx_win, 902, 52, 0, "(");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 912, 52, 0,
		ft_itoa(param->im_str.t));
	mlx_string_put(param->mlx_ptr, param->mlx_win, 922, 52, 0, ".");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 932, 52, 0,
		ft_itoa((int)(param->im_str.t * 10) % 10));
	mlx_string_put(param->mlx_ptr, param->mlx_win, 942, 52, 0, ")");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 75, 0,
		"x1.2  x1.5  x1.6  x1.8  x2");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 812, 122, 0,
		"ite max :");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 912, 122, 0,
		ft_itoa(param->im_str.end));
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 150, 0,
		"+10  +20  +50  +100  +200");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 175, 0,
		"-10  -20  -50  -100  -200");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 810, 220, 0,
		"Psychedelic:");
}

void	write_settings(t_data *param)
{
	write_settings_one(param);
	write_settings_two(param);
}
