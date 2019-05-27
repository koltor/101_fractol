/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 17:39:20 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 17:39:51 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel_to_img(UINT *img_str, int x, int y, UINT color)
{
	img_str[y * WIN_SIZE_X + x] = color;
}

void		print_image(t_monitor *m)
{
	mlx_clear_window(m->env.mlx_ptr, m->env.win_ptr);
	display_fractol(m);
	mlx_put_image_to_window(m->env.mlx_ptr,
						m->env.win_ptr, m->env.img_ptr, 0, 0);
	user_interface(m, m->env.mlx_ptr, m->env.win_ptr);
	mlx_pixel_put(m->env.mlx_ptr, m->env.win_ptr,
					WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 0xff0000);
}

int			display_fractol(t_monitor *m)
{
	if (generate_thread(m) == -1)
		return (-1);
	return (0);
}
