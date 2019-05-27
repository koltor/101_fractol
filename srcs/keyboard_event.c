/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keyboard_event.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 16:13:38 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 17:25:48 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	reset(t_fractal *frcl, t_env *env)
{
	frcl->x1 = -2.1;
	frcl->x2 = 0.6;
	frcl->y1 = -1.2;
	frcl->y2 = 1.2;
	frcl->iteration_max = 50;
	env->zoom_x = WIN_SIZE_X / (frcl->x2 - frcl->x1);
	env->zoom_y = WIN_SIZE_Y / (frcl->y2 - frcl->y1);
}

void	keyboard_events3(int key, t_monitor *mtr)
{
	if (key == 82)
		mtr->frcl.color = 0xffffff;
	else if (key == 83)
		mtr->frcl.color = 0xfff000;
	else if (key == 84)
		mtr->frcl.color = 0x000fff;
	else if (key == 85)
		mtr->frcl.color = 0x111111;
	else if (key == 86)
		mtr->frcl.color = 0x010101;
	else if (key == 87)
		mtr->frcl.color = 0x100101;
	else if (key == 88)
		mtr->frcl.color = 0x0A0A00;
	else if (key == 89)
		mtr->frcl.color = 0x16779532;
	else if (key == 91)
		mtr->frcl.color = 16779532;
}

int		keyboard_events2(int key, t_monitor *mtr)
{
	if (key == F1)
		mtr->frcl.name = "Mandelbrot";
	else if (key == F2)
		mtr->frcl.name = "Julia";
	else if (key == F3)
		mtr->frcl.name = "Deep_ship";
	else if (key == F4)
		mtr->frcl.name = "Appolonius";
	else if (key == F5)
		mtr->frcl.name = "Feigenbaum";
	if (key == F1 || key == F2 || key == F3 | key == F4 || key == F5)
		reset(&mtr->frcl, &mtr->env);
	if (key == ESC)
		exit(0);
	if (key == SPACE && mtr->stopjulia == 0)
		mtr->stopjulia = 1;
	else if (key == SPACE && mtr->stopjulia == 1)
		mtr->stopjulia = 0;
	if (key == TAB && mtr->disableui == 0)
		mtr->disableui = 1;
	else if (key == TAB && mtr->disableui == 1)
		mtr->disableui = 0;
	keyboard_events3(key, mtr);
	return (0);
}

int		keyboard_events(int key, void *data)
{
	t_monitor *mtr;

	mtr = (t_monitor*)data;
	if (key == PLUS && mtr->frcl.iteration_max < 4294967295)
		mtr->frcl.iteration_max += mtr->frcl.iteration_max / 10 + 1;
	else if (key == LESS && mtr->frcl.iteration_max > 0)
		mtr->frcl.iteration_max -= mtr->frcl.iteration_max / 10 + 1;
	else if (key == IN)
	{
		mtr->env.zoom_x += 10 + mtr->env.zoom_x / 20;
		mtr->env.zoom_y += 10 + mtr->env.zoom_y / 20;
	}
	else if (key == OUT)
	{
		mtr->env.zoom_x -= 10 + mtr->env.zoom_x / 20;
		mtr->env.zoom_y -= 10 + mtr->env.zoom_y / 20;
	}
	else
		keyboard_events2(key, mtr);
	print_image(mtr);
	return (0);
}
