/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:01:01 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/04 20:26:49 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_powerup(t_env *env)
{
	env->power++;
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
}

void	ft_powerdown(t_env *env)
{
	if (env->power > 1)
		env->power--;
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
}
