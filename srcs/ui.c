/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/25 15:32:51 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 17:23:47 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	free_multiple(void *a, void *b, void *c, void *d)
{
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
	if (d)
		free(d);
}

void	user_interface2(t_monitor *m, void *mlx, void *win)
{
	char	*stopjulia;
	char	*c;
	char	*i;

	if (!ft_strcmp("Julia", m->frcl.name))
	{
		stopjulia = ft_itoa(m->stopjulia);
		c = ft_ftoa(m->frcl.x, 3);
		i = ft_ftoa(m->frcl.y, 3);
		mlx_string_put(mlx, win, 5, WIN_SIZE_Y - 20, 0xffffff, "Pause");
		mlx_string_put(mlx, win, 100, WIN_SIZE_Y - 20, 0xffffff, stopjulia);
		mlx_string_put(mlx, win, 5, WIN_SIZE_Y - 40, 0xffffff, "I :");
		mlx_string_put(mlx, win, 100, WIN_SIZE_Y - 40, 0xffffff, i);
		mlx_string_put(mlx, win, 5, WIN_SIZE_Y - 60, 0xffffff, "C :");
		mlx_string_put(mlx, win, 100, WIN_SIZE_Y - 60, 0xffffff, c);
		free(stopjulia);
		free(c);
		free(i);
	}
}

void	user_interface(t_monitor *m, void *mlx, void *win)
{
	char *thread;
	char *iteration;
	char *zoom;
	char *color;

	if (m->disableui == 1)
		return ;
	thread = ft_itoa(NB_THREAD);
	iteration = ft_itoa(m->frcl.iteration_max);
	color = ft_itoa(m->frcl.color);
	zoom = ft_itoa(m->env.zoom_x / 1000000);
	mlx_string_put(mlx, win, WIN_SIZE_X - 120, 5, 0xff0000, "Escape: ESC");
	mlx_string_put(mlx, win, WIN_SIZE_X - 120, 25, 16762880, "Hide UI: tab");
	mlx_string_put(mlx, win, 5, 5, 0xffffff, "Fractol selectionne: F");
	mlx_string_put(mlx, win, 250, 5, 0xffffff, m->frcl.name);
	mlx_string_put(mlx, win, 5, 25, 0xffffff, "F1 F2 F3 F4 F5");
	mlx_string_put(mlx, win, 5, 45, 0xffffff, "Thread:");
	mlx_string_put(mlx, win, 250, 45, 0xffffff, thread);
	mlx_string_put(mlx, win, 5, 65, 0xffffff, "Iteration: +|-");
	mlx_string_put(mlx, win, 250, 65, m->frcl.iteration_max * 255, iteration);
	mlx_string_put(mlx, win, 5, 85, 0xffffff, "Zoom:");
	mlx_string_put(mlx, win, 250, 85, 0x99ff00, zoom);
	mlx_string_put(mlx, win, 5, 105, m->frcl.color + 15255, "Color[0 - 8]");
	free_multiple(thread, iteration, zoom, color);
	user_interface2(m, mlx, win);
}
