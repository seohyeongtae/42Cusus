/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:14:31 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/10 02:17:02 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
 
bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point	a(0, 0);
	Point	b(20, 0);
	Point	c(10, 30);
	Point	in(10, 15);
	Point	out(30, 50);

	std::cout << "Point \"in\" created at x-" << in.getx() << " y-" << in.gety() << std::endl;
	std::cout << "Point \"out\" created at x-" << out.getx() << " y-" << out.gety() << std::endl;
	if (bsp(a, b, c, in))
		std::cout << "\"in\" is in the triangle" << std::endl;
	else
		std::cout << "\"in\" is out of the triangle" << std::endl;
	if (bsp(a, b, c, out))
		std::cout << "\"out\" is in the triangle" << std::endl;
	else
		std::cout << "\"out\" is out of the triangle" << std::endl;

	return 0;
}
