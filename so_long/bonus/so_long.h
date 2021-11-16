/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:29:25 by hyseo             #+#    #+#             */
/*   Updated: 2021/11/15 21:32:59 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map
{
	int		x;
	int		y;
	char	**map_arr;
}	t_map;

typedef struct s_play
{
	int	x;
	int	y;
	int	item;
	int	walking;
}	t_play;

void	make_image_window(t_vars *vars, int n);
void	make_image_window_item(t_vars *vars, int n);
void	make_image_window_rl(t_vars *vars, int n);
void	make_image_window_item_rl(t_vars *vars, int n);

void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);

int		itoa_count(long long n, int min);
char	*itoa_set(char *result, long long n, int i);
char	*ft_itoa(int n);

void	make_map(t_vars *vars, t_map *g_map, int width, int height);
void	check_map_arr(t_map *map);
void	make_map_arr(t_map *map, char *buf, int i, int j);
void	check_map(t_map *map, int i);
void	*read_map(t_vars *vars);

int		key_control(int keycode, t_vars *vars);
int		mouse_control(int button);
void	make_map_image(t_vars *vars, int width, int height, char n);

#endif