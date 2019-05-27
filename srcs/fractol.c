/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 14:08:50 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 18:09:25 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

/*
** Function for initialisation of the environment
*/

static void	init_env(t_env *env, t_fractal frcl, char *name)
{
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, name);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y);
	env->zoom_x = WIN_SIZE_X / (frcl.x2 - frcl.x1);
	env->zoom_y = WIN_SIZE_Y / (frcl.y2 - frcl.y1);
}

static void	init_fractal(t_fractal *frcl, char *name)
{
	frcl->x1 = -2.1;
	frcl->x2 = 0.6;
	frcl->y1 = -1.2;
	frcl->y2 = 1.2;
	frcl->x = 0.285;
	frcl->y = 0.01;
	frcl->iteration_max = 50;
	frcl->color = 16779532;
	frcl->name = name;
}

static void	init_img(t_env env, t_image *m)
{
	char *str;

	str = mlx_get_data_addr(env.img_ptr, &m->bpp, &m->s_l, &m->endian);
	m->img_str = (unsigned int *)str;
}

int			fractol(char *name)
{
	t_monitor	mtr;

	mtr.stopjulia = 0;
	mtr.disableui = 0;
	mtr.id = 0;
	init_fractal(&mtr.frcl, name);
	init_env(&mtr.env, mtr.frcl, mtr.frcl.name);
	init_thread(NB_THREAD, &mtr);
	init_img(mtr.env, &mtr.img);
	mlx_mouse_hook(mtr.env.win_ptr, mouse_events, (void*)&mtr);
	mlx_hook(mtr.env.win_ptr, 6, 1L < 6, mouse_move_events, &mtr);
	mlx_hook(mtr.env.win_ptr, 2, 1, keyboard_events, (void*)&mtr);
	print_image(&mtr);
	mlx_loop(mtr.env.mlx_ptr);
	return (0);
}
