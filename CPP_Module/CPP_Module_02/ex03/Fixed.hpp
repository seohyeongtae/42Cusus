/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:40:06 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/01 23:09:43 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					value;
	const static int	bits;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &src);
	Fixed(const int	num);
	Fixed(const float num);
	Fixed & operator = (Fixed const &src);
	bool	operator > (Fixed const &src) const;
	bool	operator < (Fixed const &src) const;
	bool	operator >= (Fixed const &src) const;
	bool	operator <= (Fixed const &src) const;
	bool	operator == (Fixed const &src) const;
	bool	operator != (Fixed const &src) const;
	Fixed	operator + (Fixed const &src) const;
	Fixed	operator - (Fixed const &src) const;
	Fixed	operator * (Fixed const &src) const;
	Fixed	operator / (Fixed const &src) const;
	Fixed &	operator ++ (void);
	Fixed	operator ++ (int);
	Fixed & operator -- (void);
	Fixed	operator -- (int);

	static Fixed &			min(Fixed & f1, Fixed & f2);
	static Fixed const &	min(Fixed const & f1, Fixed const & f2);
	static Fixed &			max(Fixed & f1, Fixed & f2);
	static Fixed const &	max(Fixed const & f1, Fixed const & f2);
	
	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};
	std::ostream &	operator<<(std::ostream & s, const Fixed & fixed);
#endif
