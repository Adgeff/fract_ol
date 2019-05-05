/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:39:12 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/05 22:51:02 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int			ft_destroynotify_event(void *param)
{
	t_env	*env;

	env = param;
	ft_exit(env);
	return (0);
}

int			ft_clrpick_event(int color, void *param)
{
	t_env	*env;

	env = param;
	env->color = color;
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
	return (0);
}

int			ft_buttonpress_event(int button, int x, int y, void *param)
{
	t_env	*env;

	env = param;
	x = x - FRAC_LEN / 2;
	y = y - FRAC_LEN / 2;
	x = (x / 40) ? 40 * (x / ABS(x)) : x;
	y = (y / 40) ? 40 * (y / ABS(y)) : y;
	if ((env->lock && button == 1) || button == 4)
	{
		env->x_shift = env->x_shift + x;
		env->y_shift = env->y_shift + y;
		ft_zoomup(env);
	}
	else if (button == 1)
		env->lock = !env->lock;
	else if (button == 2 || button == 5)
	{
		env->x_shift = env->x_shift + x;
		env->y_shift = env->y_shift + y;
		ft_zoomdown(env);
	}
	return (0);
}

int			ft_motionnotify_event(int x, int y, void *param)
{
	t_env	*env;

	env = param;
	if (!env->lock)
	{
		env->c = (t_complex){((double)x - FRAC_LEN / 2) / (FRAC_LEN / 2),
			((double)y - FRAC_LEN / 2) / (FRAC_LEN / 2)};
		if (ft_drawpic(env))
			exit(EXIT_FAILURE);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
			env->img.x, env->img.y);
	}
	return (0);
}

int			ft_keypress_event(int keycode, void *param)
{
	t_env	*env;
	int		i;

	env = param;
	i = 0;
	while (ft_keyeventtab()[i].f && ft_keyeventtab()[i].keycode != keycode)
		i++;
	if (ft_keyeventtab()[i].f)
		ft_keyeventtab()[i].f(env);
	return (0);
}
