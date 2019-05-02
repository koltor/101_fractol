/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calcul_fractal2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 11:50:30 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 17:40:25 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_complexe	new_complexe(t_complexe new, double r, double i)
{
	new.r = r;
	new.i = i;
	return (new);
}

void		sect_f(t_monitor *m, t_complexe *c, t_complexe *z, t_multithread *t)
{
	if (m->frcl.name[0] == 'M' || m->frcl.name[0] == 'D' ||
													m->frcl.name[0] == 'F')
	{
		*c = new_complexe(*c, t->x / m->env.zoom_x + m->frcl.x1,
										t->y / m->env.zoom_y + m->frcl.y1);
		*z = new_complexe(*z, 0, 0);
	}
	else if (m->frcl.name[0] == 'J')
	{
		*c = new_complexe(*c, m->frcl.x, m->frcl.y);
		*z = new_complexe(*z, t->x / m->env.zoom_x + m->frcl.x1,
										t->y / m->env.zoom_y + m->frcl.y1);
	}
	else
	{
		*c = new_complexe(*c, t->x / m->env.zoom_x + m->frcl.x1,
										t->y / m->env.zoom_y + m->frcl.y1);
		*z = new_complexe(*z, 0, 0);
	}
}

void		display_fractol_section(t_monitor *m, t_multithread thread)
{
	t_complexe	z;
	t_complexe	c;
	int			i;
	double		y;

	y = thread.y - 1;
	thread.x = thread.x - 1;
	while (++thread.x - 1 < thread.x_max)
	{
		thread.y = y;
		while (++thread.y < thread.y_max)
		{
			i = -1;
			sect_f(m, &c, &z, &thread);
			while (z.r * z.r + z.i * z.i < 4 && ++i < m->frcl.iteration_max)
				z = algo_complexe(z, c, m->frcl.name);
			if (i != m->frcl.iteration_max)
				put_pixel_to_img(m->img.img_str, thread.x,
												thread.y, i * m->frcl.color);
			else
				put_pixel_to_img(m->img.img_str, thread.x, thread.y, 0);
		}
	}
}
