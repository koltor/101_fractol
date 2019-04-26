/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_fractal.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 16:37:18 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 17:09:53 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_complexe	complexe_mult(t_complexe c1, t_complexe c2)
{
	t_complexe c;

	c.r = (c1.r * c2.r) - (c1.i * c2.i);
	c.i = (c1.r * c2.i) + (c1.i * c2.r);
	return (c);
}

t_complexe	complexe_div(t_complexe c1, t_complexe c2)
{
	t_complexe c;

	c.r = ((c1.r * c2.r) + (c1.i * c2.i)) / ((c2.r * c2.r) + (c2.i * c2.i));
	c.i = ((c1.i * c2.r) - (c1.r * c2.i)) / ((c2.r * c2.r) + (c2.i * c2.i));
	return (c);
}

t_complexe	complexe_plus(t_complexe c1, t_complexe c2)
{
	t_complexe d;

	d.r = c1.r + c2.r;
	d.i = c1.i + c2.i;
	return (d);
}

t_complexe	new_complexe(t_complexe new, double r, double i)
{
	new.r = r;
	new.i = i;
	return (new);
}

t_complexe	algo_complexe(t_complexe z, t_complexe c, char *str)
{
	t_complexe tmp;

	if (str[0] == 'D')
	{
		z.i = fabs(z.i);
		z.r = fabs(z.r);
	}
	if (str[0] == 'A')
	{
		z = complexe_mult(z, z);
		tmp = complexe_mult(c, c);
		c = complexe_mult(tmp, c);
		z = complexe_plus(z, c);
		tmp = new_complexe(tmp, -1.401155, 0);
		z = complexe_plus(z, tmp);
		z = complexe_div(c, z);
		return (z);
	}
	else if (str[0] == 'F')
	{
		z = complexe_mult(z, z);
		tmp = complexe_mult(c, c);
		c = complexe_mult(tmp, c);
		z = complexe_plus(z, c);
		tmp = new_complexe(tmp, -1.401155, 0);
		z = complexe_plus(z, tmp);
		return (z);
	}
	else if (str[0] == 'M' || str[0] == 'D' || str[0] == 'J')
	{
		z = complexe_mult(z, z);
		z = complexe_plus(z, c);
		return (z);
	}
	else
	{
		z = complexe_mult(z, z);
		z = complexe_plus(z, c);
	}
	return (z);
}

void	select_fractal(t_monitor *m, t_complexe *c, t_complexe *z, t_multithread *thread)
{
	if (m->frcl.name[0] == 'M' || m->frcl.name[0] == 'D' || m->frcl.name[0] == 'F')
	{
		*c = new_complexe(*c, thread->x / m->env.zoom_x + m->frcl.x1, thread->y / m->env.zoom_y + m->frcl.y1);
		*z = new_complexe(*z, 0, 0);
	}
	else if (m->frcl.name[0] == 'J')
	{
		*c = new_complexe(*c, m->frcl.x, m->frcl.y);
		*z = new_complexe(*z, thread->x / m->env.zoom_x + m->frcl.x1, thread->y / m->env.zoom_y + m->frcl.y1);
	}
	else
	{
		*c = new_complexe(*c, thread->x / m->env.zoom_x + m->frcl.x1, thread->y / m->env.zoom_y + m->frcl.y1);
		*z = new_complexe(*z, 0, 0);
	}
}

void		display_fractol_section(t_monitor *m, t_multithread *thread)
{
	t_complexe	z;
	t_complexe	c;
	int			i;
	double		y;

	y = thread->y - 1;
	thread->x = thread->x - 1;
	while (++thread->x - 1 < thread->x_max - 1)
	{
		thread->y = y;
		while (++thread->y < thread->y_max - 1)
		{
			i = -1;
			select_fractal(m, &c, &z, thread);
			while (z.r * z.r + z.i * z.i < 4 && ++i < m->frcl.iteration_max)
				z = algo_complexe(z, c, m->frcl.name);
			if (i != m->frcl.iteration_max)
				put_pixel_to_img(m->img.img_str, thread->x, thread->y, i * m->frcl.color);
			else
				put_pixel_to_img(m->img.img_str, thread->x, thread->y, 0);
		}
	}
}

int		display_fractol(t_monitor *m)
{
	if (generate_thread(m) == -1)
		return (-1);
	return (0);
}
