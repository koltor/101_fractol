/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_fractal.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 16:37:18 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 17:33:53 by matheme     ###    #+. /#+    ###.fr     */
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

t_complexe	algo_complexe2(t_complexe z, t_complexe c, char *str)
{
	t_complexe tmp;

	if (str[0] == 'F')
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
	else
		return (algo_complexe2(z, c, str));
	return (z);
}
