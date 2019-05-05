/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:36:22 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/05 18:03:58 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int			ft_config_mlx(t_env *env)
{
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, FRAC_LEN, FRAC_LEN,
		ft_fracttab()[env->fract_index].name)) ||
		!(env->img.ptr = mlx_new_image(env->mlx_ptr, FRAC_LEN, FRAC_LEN)) ||
		!(env->clrpick_ptr = ft_colorpicker(env->mlx_ptr, &ft_clrpick_event,
		env, ft_fracttab()[env->fract_index].name)))
		return (1);
	env->img.data = mlx_get_data_addr(env->img.ptr, &(env->img.bpp),
		&(env->img.sl), &(env->img.endian));
	env->img.x_size = FRAC_LEN;
	env->img.y_size = FRAC_LEN;
	env->img.x = 0;
	env->img.y = 0;
	mlx_hook(env->win_ptr, KEYPRESS, KEYPRESSMASK, &ft_keypress_event, env);
	mlx_hook(env->win_ptr, BUTTONPRESS, BUTTONPRESSMASK,
		&ft_buttonpress_event, env);
	mlx_hook(env->win_ptr, MOTIONNOTIFY, POINTERMOTIONMASK,
		&ft_motionnotify_event, env);
	mlx_hook(env->win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
		&ft_destroynotify_event, env);
	return (0);
}

void		ft_config(t_env *env)
{
	int		i;

	env->lock = ft_fracttab()[env->fract_index].lock;
	env->itermax = ITERMAX;
	env->x_shift = 0.0;
	env->y_shift = 0.0;
	env->zoom = 1.0;
	env->c = (t_complex){0.0, 0.0};
	env->color = 0xFF0000;
	env->power = 2;
	i = 0;
	while (i < THR_NBR)
	{
		env->tab[i].param = env;
		env->tab[i].line = i;
		i++;
	}
}
