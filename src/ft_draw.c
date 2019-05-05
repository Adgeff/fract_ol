/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:38:06 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/04 14:48:14 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void			*ft_drawline(void *arg)
{
	t_thr		*thr;
	t_env		*env;
	int			i;
	int			j;

	thr = arg;
	env = thr->param;
	j = thr->line;
	while (j < FRAC_LEN)
	{
		i = 0;
		while (i < FRAC_LEN)
		{
			ft_img_pixelput(&(env->img), i, j, ft_colortab()[env->color_index].
				f(ft_fracttab()[env->fract_index].f(i, j, env), env->itermax,
				env->color));
			i++;
		}
		j = j + THR_NBR;
	}
	pthread_exit(NULL);
}

int				ft_drawpic(t_env *env)
{
	pthread_t	tab[THR_NBR];
	int			i;

	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	i = 0;
	while (i < THR_NBR)
	{
		if (pthread_create(tab + i, NULL, &ft_drawline, &(env->tab[i])))
			return (1);
		i++;
	}
	i = 0;
	while (i < THR_NBR)
	{
		if (pthread_join(tab[i], NULL))
			return (1);
		i++;
	}
	return (0);
}
