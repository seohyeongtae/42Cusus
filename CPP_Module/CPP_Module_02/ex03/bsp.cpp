/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:29:58 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/10 02:15:54 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float a_x = a.getx().toFloat();
	float a_y = a.gety().toFloat();

	float b_x = b.getx().toFloat();
	float b_y = b.gety().toFloat();

	float c_x = c.getx().toFloat();
	float c_y = c.gety().toFloat();

	float point_x = point.getx().toFloat();
	float point_y = point.gety().toFloat();
	
	float alpha = ((b_y - c_y) * (point_x - c_x) + (c_x - b_x) * (point_y - c_y)) /
				((b_y - c_y) * (a_x - c_x) + (c_x - b_x) * (a_y - c_y));
	float beta = (c_y - a_y) * (point_x - c_x) + (a_x - c_x) * (point_y - c_y) /
				((b_y - c_y) * (a_x - c_x) + (c_x - b_x) * (a_y - c_y));
	float gamma = 1.0f - alpha - beta;

	return (alpha > 0 && beta > 0 && gamma > 0);
}
