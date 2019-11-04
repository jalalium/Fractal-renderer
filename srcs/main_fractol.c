/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:02:26 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 15:31:15 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_argv(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Usage: ./fractol [option]\nList of options:\nMandelbrot\n");
		ft_putstr("Julia\nInverted_Mandelbrot\nTeardrop\nTwo_Mans\n");
		exit(0);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments\n");
		exit(0);
	}
	else
	{
		if (ft_strcmp(argv[1], "Mandelbrot") != 0 &&
ft_strcmp(argv[1], "Julia") != 0 && ft_strcmp(argv[1],
"Inverted_Mandelbrot") != 0 && ft_strcmp(argv[1],
"Teardrop") != 0 && ft_strcmp(argv[1], "Two_Mans") != 0)
		{
			ft_putstr("No Match, sorry\n");
			exit(0);
		}
	}
}

int		whichfrac(char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		return (1);
	if (ft_strcmp(str, "Inverted_Mandelbrot") == 0)
		return (2);
	if (ft_strcmp(str, "Julia") == 0)
		return (3);
	if (ft_strcmp(str, "Teardrop") == 0)
		return (4);
	if (ft_strcmp(str, "Two_Mans") == 0)
		return (5);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data			data;
	unsigned char	*str1;
	unsigned char	*str2;
	int				a;

	check_argv(argc, argv);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1100,
		1015, ft_strjoin("FRACTOL :  ", argv[1]));
	data.img1 = mlx_new_image(data.mlx_ptr, 800, 800);
	str1 = (unsigned char*)mlx_get_data_addr(data.img1, &(a), &(a), &(a));
	data.img2 = mlx_xpm_file_to_image(data.mlx_ptr, "ok.xpm", &a, &a);
	data.img3 = mlx_xpm_file_to_image(data.mlx_ptr, "lol.xpm", &a, &a);
	(data.im_str) = (t_image){&str1,
		&str2, 3, 0.7, 0.7, 50, 0, 0, 0, 1.2, 800, 80, 0, 0, 1,
		whichfrac(argv[1]), 0, 0, 0, -1, 0, 0};
	mlx_hook(data.mlx_win, 4, 0, mouse_press, &data);
	mlx_hook(data.mlx_win, 2, 0, deal_key, &data);
	mlx_hook(data.mlx_win, 6, 0, julia_var, &data);
	mlx_loop(data.mlx_ptr);
}
