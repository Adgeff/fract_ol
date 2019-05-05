/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:52:17 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 10:43:11 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_iterup(t_env *env)
{
	env->itermax++;
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
}

void	ft_iterdown(t_env *env)
{
	if (env->itermax > 1)
		env->itermax--;
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
}
