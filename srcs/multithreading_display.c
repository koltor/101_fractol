/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multithreading_display.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 19:25:55 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 18:20:44 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		init_thread(unsigned char nb_thread, t_monitor *m)
{
	int		i;
	double	portion;

	i = 0;
	portion = (double)WIN_SIZE_X / (double)nb_thread;
	while (i < NB_THREAD)
	{
		m->thread[i].x = i * portion;
		m->thread[i].x_max = (i + 1) * (portion) - 1;
		m->thread[i].y = 0;
		m->thread[i].y_max = WIN_SIZE_Y;
		i++;
	}
}

void		*threadfunc(void *arg)
{
	t_monitor	*m;
	int			i;

	m = (t_monitor*)arg;
	i = m->id++;
	if (m->id >= NB_THREAD)
		m->id = 0;
	if (i >= NB_THREAD)
		i = NB_THREAD - 1;
	display_fractol_section(m, m->thread[i]);
	return (NULL);
}

int			generate_thread(t_monitor *m)
{
	int i;

	i = -1;
	while (++i < NB_THREAD)
		pthread_create(&m->thread[i].pth, NULL, threadfunc, m);
	i = -1;
	while (++i < NB_THREAD)
		pthread_join(m->thread[i].pth, NULL);
	return (0);
}
