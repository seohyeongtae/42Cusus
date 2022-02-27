/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:40:06 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/25 21:36:44 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					value;
	const static int	bits;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed &src);
	Fixed & operator = (Fixed const &src);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
#endif
