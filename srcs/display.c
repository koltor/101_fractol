/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 11:50:30 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/25 15:44:16 by matheme     ###    #+. /#+    ###.fr     */
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
	user_interface(m);
	mlx_pixel_put(m->env.mlx_ptr, m->env.win_ptr,
					WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 0xff0000);
}
