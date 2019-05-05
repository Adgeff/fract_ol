/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:15:51 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 12:48:45 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int					fract_ol(void *mlx_ptr, int *win_nbr, char *name)
{
	t_env			*env;
	int				i;

	i = 0;
	while (ft_fracttab()[i].f && ft_strcmp(ft_fracttab()[i].name, name))
		i++;
	if (ft_fracttab()[i].f)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env))))
			return (1);
		env->mlx_ptr = mlx_ptr;
		(*win_nbr)++;
		env->win_nbr = win_nbr;
		env->fract_index = i;
		env->color_index = 0;
		ft_config(env);
		if (ft_config_mlx(env) ||
			ft_drawpic(env))
			return (1);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
			env->img.x, env->img.y);
	}
	else
		return (-1);
	return (0);
}

void				ft_run(void *mlx_ptr)
{
	ft_putendl("Press H for help");
	mlx_loop(mlx_ptr);
}

int					main(int argc, char **argv)
{
	void			*mlx_ptr;
	int				win_nbr;
	int				i;
	int				ret;
	int				wrong;

	if (!(mlx_ptr = mlx_init()))
		return (1);
	win_nbr = 0;
	i = 1;
	wrong = 0;
	while (i < argc)
	{
		if ((ret = fract_ol(mlx_ptr, &win_nbr, argv[i])) < 0 &&
			(wrong = 1))
			ft_errarg(ft_getexecname(argv[0]), argv[i]);
		else if (ret)
			return (1);
		i++;
	}
	if (argc < 2 || wrong)
		ft_usage(ft_getexecname(argv[0]));
	if (win_nbr)
		ft_run(mlx_ptr);
	return (0);
}
