/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multithreading.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 19:25:55 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 17:19:56 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			*threadfunc(void *arg)
{
	t_monitor		*m;
	t_multithread	*thread;

	m = (t_monitor*)arg;
	thread = m->thread;
	while (thread->id != m->id)
		thread = thread->next;
	m->id++;
	display_fractol_section(m, thread);
	pthread_exit(NULL);
	return (NULL);
}

t_multithread	*new_multithread(double x, double x_max, UINT id)
{
	t_multithread	*m;

	if (!(m = malloc(sizeof(t_multithread))))
		return (NULL);
	m->x = x;
	m->y = 0;
	m->x_max = x_max;
	m->y_max = WIN_SIZE_Y;
	m->id = id;
	m->next = NULL;
	return (m);
}

static void			free_thread(t_multithread *begin)
{
	t_multithread	*tmp;

	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
}

int				generate_thread(t_monitor *m)
{
	unsigned int	section_x;
	unsigned int	i;
	t_multithread	*begin;
	t_multithread	*tmp;

	m->id = 0;
	section_x = WIN_SIZE_X / m->nb_thread;
	if (!(m->thread = new_multithread(0, section_x, 0)))
		return (-1);
	begin = m->thread;
	i = 0;
	while (++i < m->nb_thread)
	{
		if (!(m->thread->next = new_multithread(section_x * i, section_x * (i + 1), i)))
			return (-1);
		m->thread = m->thread->next;
	}
	m->thread = begin;
	tmp = begin;
	while (tmp)
	{
		pthread_create(&tmp->pth, NULL, threadfunc, m);
		tmp = tmp->next;
	}
	while (m->thread)
	{
		pthread_join(m->thread->pth, NULL);
		m->thread = m->thread->next;
	}
	free_thread(begin);
	return (0);
}
