/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:41:33 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/02 01:14:29 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() {
	this->value = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int num) {
	//std::cout << "Int constructor called" << std::endl;
	this->value = num << this->bits;
}

Fixed::Fixed(const float num) {
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->bits));
}

Fixed &Fixed::operator = (Fixed const &src) {
	//std::cout << "Assignation operator called" << std::endl;
	this->value = src.value;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(const int raw) {
	this->value = raw;
}

float	Fixed::toFloat(void) const {
	return (float(this->value) / (1 << this->bits));
}

int	Fixed::toInt(void) const {
	return (this->value >> this->bits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool	Fixed::operator>(Fixed const & src) const
{
	return (this->value < src.value);
}

bool	Fixed::operator<(Fixed const & src) const
{
	return (this->value > src.value);
}

bool	Fixed::operator>=(Fixed const & src) const
{
	return (this->value >= src.value);
}

bool	Fixed::operator<=(Fixed const & src) const
{
	return (this->value <= src.value);
}

bool	Fixed::operator==(Fixed const & src) const
{
	return (this->value == src.value);
}

bool	Fixed::operator!=(Fixed const & src) const
{
	return (this->value != src.value);
}

Fixed	Fixed::operator+(Fixed const & src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed & Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	f(*this);

	this->value++;
	return (f);
}

Fixed & Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	f(*this);

	this->value--;
	return (f);
}

Fixed &	Fixed::min(Fixed & f1, Fixed & f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed const &	Fixed::min(Fixed const & f1, Fixed const & f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed &	Fixed::max(Fixed & f1, Fixed & f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed const &	Fixed::max(Fixed const & f1, Fixed const & f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}
