/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:40:06 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/25 23:39:16 by hyseo            ###   ########.fr       */
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
	
	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};
	std::ostream &	operator<<(std::ostream & s, const Fixed & fixed);
#endif
