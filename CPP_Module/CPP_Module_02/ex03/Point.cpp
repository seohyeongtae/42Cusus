/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:56:05 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/10 02:12:38 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(Point const & p) : x(p.x), y(p.y) {}

Point & Point::operator=(Point const &p) {
	const_cast<Fixed &>(x) = p.getx();
	const_cast<Fixed &>(y) = p.gety(); 
	return (*this);
}

Fixed Point::getx() const{
	return (x);
}

Fixed Point::gety() const {
	return (y);
}

Point::~Point() {}