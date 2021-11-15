/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:36:56 by hyseo             #+#    #+#             */
/*   Updated: 2021/11/15 19:37:13 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

extern t_map g_map;
extern t_play g_play;

void	move_up(t_vars *vars)
{
	void	*image;
	int		img_width;
	int		img_hight;

	if (g_map.map_arr[g_play.y - 1][g_play.x] == '0')
		make_image_window(vars, -1);
	else if (g_map.map_arr[g_play.y - 1][g_play.x] == 'C')
		make_image_window_item(vars, -1);
	else if (g_map.map_arr[g_play.y - 1][g_play.x] == 'E' && g_play.item == 0)
		exit(1);
}

void	move_down(t_vars *vars)
{
	void	*image;
	int		img_width;
	int		img_hight;

	if (g_map.map_arr[g_play.y + 1][g_play.x] == '0')
		make_image_window(vars, 1);
	else if (g_map.map_arr[g_play.y + 1][g_play.x] == 'C')
		make_image_window_item(vars, 1);
	else if (g_map.map_arr[g_play.y + 1][g_play.x] == 'E' && g_play.item == 0)
		exit(1);
}

void	move_left(t_vars *vars)
{
	void	*image;
	int		img_width;
	int		img_hight;

	if (g_map.map_arr[g_play.y][g_play.x - 1] == '0')
		make_image_window_rl(vars, -1);
	else if (g_map.map_arr[g_play.y][g_play.x - 1] == 'C')
		make_image_window_item_rl(vars, -1);
	else if (g_map.map_arr[g_play.y][g_play.x - 1] == 'E' && g_play.item == 0)
		exit(1);
}

void	move_right(t_vars *vars)
{
	void	*image;
	int		img_width;
	int		img_hight;

	if (g_map.map_arr[g_play.y][g_play.x + 1] == '0')
		make_image_window_rl(vars, 1);
	else if (g_map.map_arr[g_play.y][g_play.x + 1] == 'C')
		make_image_window_item_rl(vars, 1);
	else if (g_map.map_arr[g_play.y][g_play.x + 1] == 'E' && g_play.item == 0)
		exit(1);
}
