/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:34:30 by hyseo             #+#    #+#             */
/*   Updated: 2021/11/15 19:36:17 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

extern t_map g_map;
extern t_play g_play;

void	make_image_window(t_vars *vars, int n)
{
	void	*image;
	int		img_width;
	int		img_hight;

	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/hero.xpm", &img_width, &img_hight);
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, g_play.x * 60, (g_play.y + n) * 60);
	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/field.xpm", &img_width, &img_hight);
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, g_play.x * 60, g_play.y * 60);
	g_play.y += n;
	g_play.walking += 1;
	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/wall.xpm", &img_width, &img_hight);
	mlx_put_image_to_window(vars->mlx, vars->win, image, 0 * 60, 0 * 60);
}

void	make_image_window_item(t_vars *vars, int n)
{
	void	*image;
	int		img_width;
	int		img_hight;

	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/hero.xpm", &img_width, &img_hight);
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, g_play.x * 60, (g_play.y + n) * 60);
	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/field.xpm", &img_width, &img_hight);
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, g_play.x * 60, g_play.y * 60);
	g_map.map_arr[g_play.y + n][g_play.x] = '0';
	g_play.y += n;
	g_play.walking += 1;
	g_play.item -= 1;
	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/wall.xpm", &img_width, &img_hight);
	mlx_put_image_to_window(vars->mlx, vars->win, image, 0 * 60, 0 * 60);
}

void	make_image_window_rl(t_vars *vars, int n)
{
	void	*image;
	int		img_width;
	int		img_hight;

	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/hero.xpm", &img_width, &img_hight);
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, (g_play.x + n) * 60, g_play.y * 60);
	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/field.xpm", &img_width, &img_hight);
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, g_play.x * 60, g_play.y * 60);
	g_play.x += n;
	g_play.walking += 1;
	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/wall.xpm", &img_width, &img_hight);
	mlx_put_image_to_window(vars->mlx, vars->win, image, 0 * 60, 0 * 60);
}

void	make_image_window_item_rl(t_vars *vars, int n)
{
	void	*image;
	int		img_width;
	int		img_hight;

	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/hero.xpm", &img_width, &img_hight);
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, (g_play.x + n) * 60, g_play.y * 60);
	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/field.xpm", &img_width, &img_hight);
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, g_play.x * 60, g_play.y * 60);
	g_map.map_arr[g_play.y][g_play.x + n] = '0';
	g_play.x += n;
	g_play.walking += 1;
	g_play.item -= 1;
	image = mlx_xpm_file_to_image
		(vars->mlx, "./picture/wall.xpm", &img_width, &img_hight);
	mlx_put_image_to_window(vars->mlx, vars->win, image, 0 * 60, 0 * 60);
}
