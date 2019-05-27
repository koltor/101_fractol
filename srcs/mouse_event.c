/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_event.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 17:25:29 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 17:26:53 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_events(int button, int x, int y, void *data)
{
	t_monitor	*mtr;
	double		zoomx;
	double		zoomy;

	mtr = (t_monitor*)data;
	zoomx = (mtr->env.zoom_x / 128);
	zoomy = (mtr->env.zoom_y / 128);
	if (button == ZOOM_IN)
	{
		mtr->frcl.x1 += ((double)x / (WIN_SIZE_X / 2) - 1) / zoomx;
		mtr->frcl.y1 += ((double)y / (WIN_SIZE_Y / 2) - 1) / zoomy;
		mtr->frcl.x2 -= ((double)x / (WIN_SIZE_X / 2) - 1) / zoomx;
		mtr->frcl.y2 -= ((double)y / (WIN_SIZE_Y / 2) - 1) / zoomy;
		print_image(mtr);
	}
	else if (button == ZOOM_OUT)
	{
		mtr->frcl.x1 += ((double)x / (WIN_SIZE_X / 2) - 1) / zoomx;
		mtr->frcl.y1 += ((double)y / (WIN_SIZE_Y / 2) - 1) / zoomy;
		mtr->frcl.x2 -= ((double)x / (WIN_SIZE_X / 2) - 1) / zoomx;
		mtr->frcl.y2 -= ((double)y / (WIN_SIZE_Y / 2) - 1) / zoomy;
		print_image(mtr);
	}
	return (0);
}

int		mouse_move_events(int x, int y, void *data)
{
	t_monitor	*mtr;

	mtr = (t_monitor*)data;
	if (mtr->stopjulia == 0 && ft_strcmp(mtr->frcl.name, "Julia") == 0)
	{
		mtr->frcl.x = (double)x / WIN_SIZE_X * 4 - 4;
		mtr->frcl.y = (double)y / WIN_SIZE_Y * 4 - 4;
		print_image(mtr);
	}
	return (0);
}
