/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:02:10 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/01 23:02:59 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// 8 1000
// 1000
// 100000000
// 1000 00000000            10 =  1010
// 10 == 2560                2048  + 512 2^9   <<8
// 10.0 = 2560  10.1 = 2586   10.5 = 2688   2048 + 512  + 128
//				1010.000			1010.1 0000000
//       1280      1280      1024  + 256 2^8   <<7
// 42.42 = 10860  -42.42 = -10860 
// 42 = 10752
 
// Fixed  *e = new Fixed (10);
// Fixed *&i = e;
 
int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
