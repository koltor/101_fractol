/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ftoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/26 18:39:40 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 19:28:42 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static double	ft_power_for_f(double f, int precision)
{
	if (precision == 0)
		return (f);
	return (ft_power_for_f(f * 10, precision - 1));
}

static char		*free_str(char *a, char *b)
{
	free(a);
	free(b);
	return (NULL);
}

char			*ft_ftoa(double f, int precision)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		e;

	if (precision > 10)
		return (NULL);
	e = (int)f;
	s1 = ft_itoa(e);
	f = f - e;
	f = ft_power_for_f(f, precision);
	e = (int)f;
	if (e < 0)
		e = -e;
	s2 = ft_itoa(e);
	if (!(s3 = ft_strjoin(s1, ".")))
		return (free_str(s1, s2));
	free(s1);
	if (!(s1 = ft_strjoin(s3, s2)))
		return (free_str(s2, s3));
	free(s2);
	free(s3);
	return (s1);
}
