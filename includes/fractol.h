/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 14:09:19 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 18:10:16 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** this project is setup in base 0
** -1	= error
** 0	= everithing ok
** 1	= something wrong
*/

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>

# define NB_THREAD 8
# define UINT unsigned int

/*
** size X and Y of windows
*/
# define WIN_SIZE_X 700
# define WIN_SIZE_Y 700

/*
** define for keyboard_keys
*/
# define ESC		53
# define SPACE		49
# define PLUS		69
# define LESS		78
# define IN			126
# define OUT		125
# define THRD_UP	116
# define THRD_DOWN	121
# define F1			122
# define F2			120
# define F3			99
# define F4			118
# define F5			96
# define TAB		48

/*
** define for mouse button
*/
# define ZOOM_IN	5
# define ZOOM_OUT	4

/*
** nombre complexe
*/
typedef struct			s_complexe
{
	double				r;
	double				i;
}						t_complexe;

/*
** struct for the control of the environnemnent
*/

typedef struct			s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;

	double				zoom_x;
	double				zoom_y;
}						t_env;

typedef struct			s_image
{
	unsigned int		*img_str;
	int					bpp;
	int					s_l;
	int					endian;
}						t_image;

typedef struct			s_fractal
{
	char				*name;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				x;
	double				y;
	unsigned int		iteration_max;
	unsigned int		color;
}						t_fractal;

typedef	struct			s_multhread
{
	pthread_t			pth;
	double				x;
	double				y;
	double				x_max;
	double				y_max;
}						t_multithread;

typedef	struct			s_monitor
{
	struct s_env		env;
	struct s_image		img;
	struct s_fractal	frcl;
	t_multithread		thread[NB_THREAD];
	unsigned char		stopjulia;
	unsigned char		disableui;
	unsigned int		id;
}						t_monitor;

/*
** allow events
*/
int						keyboard_events(int key, void *data);
int						mouse_events(int button, int x, int y, void *data);
int						mouse_move_events(int x, int y, void *data);

/*
** display fractal
*/

int						display_fractol(t_monitor *monitor);
void					put_pixel_to_img(unsigned int *img, int x, int y,
														unsigned int color);
void					print_image(t_monitor *monitor);
void					user_interface(t_monitor *m, void *mlx, void *win);

/*
** multithreading
*/

int						generate_thread(t_monitor *m);
void					init_thread(unsigned char nb_thread, t_monitor *m);
void					display_fractol_section(t_monitor *m, t_multithread t);

/*
** complexe
*/

t_complexe				new_complexe(t_complexe new, double r, double i);
t_complexe				algo_complexe(t_complexe z, t_complexe c, char *str);

int						usage();
int						fractol();
#endif
