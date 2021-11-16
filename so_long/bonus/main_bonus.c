/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:34:29 by hyseo             #+#    #+#             */
/*   Updated: 2021/11/16 16:41:35 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	g_map;
t_play	g_play;

int	key_control(int keycode, t_vars *vars)
{
	char	*walk;

	if (keycode == 13)
		move_up(vars);
	else if (keycode == 0)
		move_left(vars);
	else if (keycode == 1)
		move_down(vars);
	else if (keycode == 2)
		move_right(vars);
	else if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		write(1, "Game closed\n", 12);
		exit(1);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		walk = ft_itoa(g_play.walking);
		mlx_string_put(vars->mlx, vars->win, 5, 5, 0x00FF0000, walk);
		free(walk);
	}
	else
		write(1, "unknown key\n", 12);
	return (1);
}

int	mouse_control(int button)
{
	if (button == 2)
	{
		write(1, "map error\n", 10);
		exit(1);
	}
	else
	{
		write(1, "Game closed\n", 12);
		exit(1);
	}
	return (1);
}

void	make_map_image(t_vars *vars, int width, int height, char n)
{
	void	*image;
	int		img_width;
	int		img_hight;

	if (n == '1')
		image = mlx_xpm_file_to_image
			(vars->mlx, "./picture/wall.xpm", &img_width, &img_hight);
	if (n == '0')
		image = mlx_xpm_file_to_image
			(vars->mlx, "./picture/field.xpm", &img_width, &img_hight);
	if (n == 'C')
		image = mlx_xpm_file_to_image
			(vars->mlx, "./picture/item.xpm", &img_width, &img_hight);
	if (n == 'P')
	{
		image = mlx_xpm_file_to_image
			(vars->mlx, "./picture/hero.xpm", &img_width, &img_hight);
		g_map.map_arr[height][width] = '0';
	}
	if (n == 'E')
		image = mlx_xpm_file_to_image
			(vars->mlx, "./picture/exit.xpm", &img_width, &img_hight);
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, width * 60, height * 60);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = read_map(&vars);
	mlx_hook(vars.win, 17, 1L << 0, mouse_control, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
