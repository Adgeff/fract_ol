/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:53:59 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 12:28:05 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		ft_reset(t_env *env)
{
	ft_config(env);
	ft_reset_colorpicker(env->clrpick_ptr);
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
}

void		ft_exit(t_env *env)
{
	int		*win_nbr;

	win_nbr = env->win_nbr;
	ft_close_colorpicker(env->clrpick_ptr);
	mlx_destroy_image(env->mlx_ptr, env->img.ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	free(env);
	(*win_nbr)--;
	if (!(*win_nbr))
		exit(EXIT_SUCCESS);
}

void		ft_lock(t_env *env)
{
	if (ft_fracttab()[env->fract_index].lock == 0)
		env->lock = !env->lock;
}

void		ft_help(t_env *env)
{
	(void)env;
	ft_putendl("Key list :");
	ft_putendl("+/- (numeric keypad) : increase/decrease zoom");
	ft_putendl("+/- : increase/decrease itermax");
	ft_putendl("arrows : move into the window");
	ft_putendl("6/3 : increase/decrease color algorithm");
	ft_putendl("5/2 : increase/decrease equation power");
	ft_putendl("4/1 : change fractal");
	ft_putendl("space : lock/unlock julia forms");
	ft_putendl("H : print help");
	ft_putendl("R : reset fractal");
	ft_putendl("esc : exit window (you can also use the cross)");
	ft_putendl("wheel and left/right click : increase/decrease zoom on cursor");
}
