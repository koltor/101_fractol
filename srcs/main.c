/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 16:43:09 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 16:43:28 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

/*
** main of program
*/

int			main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac != 2)
		return (usage());
	if (ft_strcmp(av[1], "Mandelbrot") != 0 && ft_strcmp(av[1], "Julia") != 0 &&
		ft_strcmp(av[1], "Deep_sheep") != 0 &&
		ft_strcmp(av[1], "Appolonius") != 0 &&
		ft_strcmp(av[1], "Feigenbaum") != 0)
		return (usage());
	fractol(av[i]);
	return (0);
}
