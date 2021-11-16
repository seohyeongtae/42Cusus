/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:38:44 by hyseo             #+#    #+#             */
/*   Updated: 2021/11/16 16:50:56 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

extern t_map	g_map;
extern t_play	g_play;

void	make_map(t_vars *vars, t_map *g_map, int width, int height)
{
	while (height < g_map->y - 1 || width < g_map->x)
	{
		if (g_map->map_arr[height][width] == '\n')
		{
			height++;
			width = 0;
		}
		else
		{
			make_map_image(vars, width, height, g_map->map_arr[height][width]);
			width++;
		}
	}
}

void	check_map_arr(t_map *map)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	while (i < map->x)
	{
		if (map->map_arr[0][i] != '1')
			error = 1;
		if (map->map_arr[map->y - 1][i++] != '1')
			error = 1;
	}
	i = 0;
	while (i < map->y)
	{
		if (map->map_arr[i][0] != '1')
			error = 1;
		if (map->map_arr[i++][map->x - 1] != '1')
			 error = 1;
	}
	if (error == 1)
	{
		write(1, "map error\n", 10);
		exit(1);
	}
}

void	make_map_arr(t_map *map, char *buf, int i, int j)
{
	while (*buf)
	{
		if (*buf == 'P')
		{
			if (g_play.x)
			{
				write(1, "map(P) error\n", 13);
				exit(1);
			}
			g_play.x = i;
			g_play.y = j;
		}
		if (*buf == 'C')
			g_play.item++;
		if (*buf == '\n')
		{
			map->map_arr[j][i] = *buf;
			map->map_arr[j++][i + 1] = '\0';
			i = 0;
		}
		else
			map->map_arr[j][i++] = *buf;
		buf++;
	}
	check_map_arr(map);
}

void	check_map(t_map *map, int i)
{
	char	buf[20000];
	int		fd;
	int		j;

	j = 0;
	fd = open("./map/map3.ber", O_RDONLY);
	read(fd, buf, 20000);
	while (buf[i])
	{
		if (buf[i] != '0' && buf[i] != 'P' && buf[i] != 'C'
			&& buf[i] != 'E' && buf[i] != '\n' && buf[i] != '1')
			mouse_control(2);
		if (buf[i++] == '\n')
			map->y += 1;
		else
			map->x += 1;
	}
	close(fd);
	map->x = map->x / map->y;
	map->map_arr = (char **) malloc(sizeof(char *) * map->y);
	while (j < map->y)
		map->map_arr[j++] = (char *) malloc(sizeof (char) * map->x);
	make_map_arr(map, buf, 0, 0);
}

void	*read_map(t_vars *vars)
{
	check_map(&g_map, 0);
	vars->win = mlx_new_window
		(vars->mlx, g_map.x * 60, g_map.y * 60, "hyseo World!");
	make_map(vars, &g_map, 0, 0);
	mlx_key_hook(vars->win, key_control, vars);
	return (vars->win);
}
