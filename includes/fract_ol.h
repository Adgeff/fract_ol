/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 02:45:25 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 11:59:10 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# include "libft.h"
# include "mlx.h"
# include "ft_colorpicker.h"
# include "mlx_keycode.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <pthread.h>

# define FRAC_LEN 800
# define ABS(x) ((x < 0) ? -x : x)

# define THR_NBR 16
# define ITERMAX 128
# define ZOOM_STEP 1.1
# define SHIFT_STEP 50

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct	s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			x_size;
	int			y_size;
	int			x;
	int			y;
}				t_img;

typedef struct	s_thr
{
	void		*param;
	int			line;
}				t_thr;

typedef struct	s_env
{
	void		*mlx_ptr;
	int			*win_nbr;
	void		*win_ptr;
	void		*clrpick_ptr;
	int			fract_index;
	int			color_index;
	t_img		img;
	int			itermax;
	t_complex	c;
	double		x_shift;
	double		y_shift;
	double		zoom;
	int			lock;
	int			color;
	int			power;
	t_thr		tab[THR_NBR];
}				t_env;

typedef struct	s_fract
{
	char		*name;
	int			(*f)(int, int, t_env *);
	int			lock;
}				t_fract;

typedef struct	s_color
{
	int			(*f)(int, int, int);
}				t_color;

typedef struct	s_keyevent
{
	int			keycode;
	void		(*f)(t_env *);
}				t_keyevent;

t_complex		ft_addz(t_complex a, t_complex b);
t_complex		ft_subz(t_complex a, t_complex b);
t_complex		ft_mulz(t_complex a, t_complex b);
t_complex		ft_divz(t_complex a, t_complex b);
t_complex		ft_powerz(t_complex n, unsigned int power);
void			ft_img_pixelput(t_img *img, int x, int y, int color);
int				ft_mandelbrot(int x, int y, t_env *env);
int				ft_julia(int x, int y, t_env *env);
int				ft_burningship(int x, int y, t_env *env);
int				ft_tricorn(int x, int y, t_env *env);
int				ft_circle(int x, int y, t_env *env);
int				ft_julia84(int x, int y, t_env *env);
int				ft_hourglass(int x, int y, t_env *env);
int				ft_checkerboard(int x, int y, t_env *env);
t_fract			*ft_fracttab(void);
int				ft_color1(int iter, int itermax, int color);
int				ft_color2(int iter, int itermax, int color);
int				ft_color3(int iter, int itermax, int color);
int				ft_color4(int iter, int itermax, int color);
int				ft_color5(int iter, int itermax, int color);
int				ft_color6(int iter, int itermax, int color);
int				ft_color7(int iter, int itermax, int color);
int				ft_color8(int iter, int itermax, int color);
int				ft_color9(int iter, int itermax, int color);
int				ft_color10(int iter, int itermax, int color);
int				ft_color11(int iter, int itermax, int color);
int				ft_color12(int iter, int itermax, int color);
t_color			*ft_colortab(void);
char			*ft_getexecname(char *path);
void			ft_errarg(char *name, char *arg);
void			ft_usage(char *name);
void			ft_config(t_env *env);
void			*ft_drawline(void *arg);
int				ft_drawpic(t_env *env);
int				ft_destroynotify_event(void *param);
int				ft_clrpick_event(int color, void *param);
int				ft_buttonpress_event(int button, int x, int y, void *param);
int				ft_motionnotify_event(int x, int y, void *param);
int				ft_keypress_event(int keycode, void *param);
int				ft_config_mlx(t_env *env);
t_keyevent		*ft_keyeventtab(void);
void			ft_zoomup(t_env *env);
void			ft_zoomdown(t_env *env);
void			ft_iterup(t_env *env);
void			ft_iterdown(t_env *env);
void			ft_shiftup(t_env *env);
void			ft_shiftdown(t_env *env);
void			ft_shiftright(t_env *env);
void			ft_shiftleft(t_env *env);
void			ft_colorup(t_env *env);
void			ft_colordown(t_env *env);
void			ft_powerup(t_env *env);
void			ft_powerdown(t_env *env);
void			ft_fractup(t_env *env);
void			ft_fractdown(t_env *env);
void			ft_lock(t_env *env);
void			ft_help(t_env *env);
void			ft_reset(t_env *env);
void			ft_exit(t_env *env);

#endif
