/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:44:40 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 13:55:48 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

typedef struct		s_image
{
	unsigned char	**ytr;
	unsigned char	**ztr;
	double			blue;
	double			red;
	double			green;
	int				end;
	int				i;
	double			a;
	double			b;
	double			t;
	int				wid;
	int				height;
	double			jul_x;
	double			jul_y;
	int				stop;
	int				type;
	int				c;
	int				fil;
	int				mag;
	int				lock;
	int				trap;
	int				lat;
}					t_image;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img1;
	void			*img2;
	void			*img3;
	t_image			im_str;
}					t_data;

typedef struct		s_burst
{
	long double		x;
	long double		y;
	long double		a;
	long double		b;
	int				end;
	int				trap;
}					t_burst;

typedef struct		s_area
{
	unsigned char	**str;
	int				offset;
	double			blue;
	double			red;
	double			green;
	int				end;
	int				i;
	double			a;
	double			b;
	double			t;
	int				wid;
	int				height;
	double			jx;
	double			jy;
	int				type;
	int				col;
	int				trap;
	int				lat;
}					t_area;
void				*draw_frac(void *arg);
void				*julia(void *arg);
void				event_three(t_data *param, int x, int y);
void				event_four(t_data *param, int x, int y);
int					col_blue(double ite, int end, double blue, int c);
int					col_red(double ite, int end, double red, int c);
int					col_green(double ite, int end, double green, int c);
int					pal_blue(double ite, int end);
int					pal_red(double ite, int end);
int					pal_green(double ite, int end);
void				apply_emboss(unsigned char **strp, unsigned char *gauss,
		int i, int j);
void				emboss(unsigned char **strp, int mag);
void				copy_image(unsigned char **str, unsigned char **ptr);
void				apply_blur(unsigned char **strp, unsigned char *gauss,
		int i, int j);
void				blur(unsigned char **strp, int mag);
void				apply_smooth(unsigned char **strp, unsigned char *gauss,
		int i, int j);
void				smooth(unsigned char **strp, int mag);
void				*draw_frac(void *arg);
void				mandelbrot(t_data *p, int i);
void				assemble(unsigned char **ptr, unsigned char **str);
void				*tear(void *arg);
void				populate_tear(t_area *z, long double x,
		long double y, int j);
void				to_image(t_area *z, long double temp, int i, int j);
double				burstt(t_burst v, double i, double distance);
double				burstm(t_burst v, double i, double di);
void				populate_man(t_area *z, long double x,
		long double y, int j);
void				*man(void *arg);
void				check_argv(int argc, char **argv);
int					whichfrac(char *str);
double				burstinv(t_burst v, double i, double distance);
void				populate_inv(t_area *z, long double x,
		long double y, int j);
void				*inv_man(void *arg);
void				write_settings_one(t_data *param);
void				write_settings_two(t_data *param);
void				write_settings(t_data *param);
int					burstj(t_burst v, double i, double distance);
void				populate_julia(t_area *z, long double x,
		long double y, int j);
void				*julia(void *arg);
double				burstm(t_burst v, double i, double di);
void				*man(void *arg);
double				bursttwo(t_burst v, double i, double distance);
void				populate_two(t_area *z, long double x,
		long double y, int j);
void				*two(void *arg);
void				event_blur(t_data *param, int x, int y);
void				event_smooth(t_data *param, int x, int y);
void				event_emboss(t_data *param, int x, int y);
void				event_man(t_data *param, int x, int y);
void				event_inv(t_data *param, int x, int y);
void				filter(t_data *param);
void				event_one(t_data *param, int x, int y);
void				event_two(t_data *param);
void				event_opt_zoom(t_data *param, int x, int y);
void				event_col_psy(t_data *param, int x, int y);
void				event_opt_iter(t_data *param, int x, int y);
void				event_colors(t_data *param, int x, int y);
void				todo(t_data *g);
void				event_three(t_data *g, int x, int y);
void				event_four(t_data *g, int x, int y);
void				apply_emboss(unsigned char **strp,
		unsigned char *gauss, int i, int j);
void				emboss(unsigned char **strp, int mag);
void				assemble(unsigned char **ptr, unsigned char **str);
void				mandelbrot(t_data *p, int i);
void				*draw_frac(void *arg);
int					deal_key(int key, t_data *param);
int					mouse_press(int button, int x, int y, t_data *param);
int					julia_var(int x, int y, t_data *param);
int					col_blue(double ite, int end, double blue, int c);
int					col_red(double ite, int end, double red, int c);
int					col_green(double ite, int end, double green, int c);
void				copy_image(unsigned char **str, unsigned char **ptr);
void				apply_blur(unsigned char **strp,
		unsigned char *gauss, int i, int j);
void				blur(unsigned char **strp, int mag);
#endif
