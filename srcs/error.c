/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/30 18:37:17 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 11:58:54 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		usage(void)
{
	write(1, "usage fractol [Mandelbrot - Julia -", 35);
	write(1, " Deep_sheep - Appolonius - Feigenbaum]\n", 40);
	return (1);
}
