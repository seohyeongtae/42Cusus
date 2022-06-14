/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:54:31 by hyseo             #+#    #+#             */
/*   Updated: 2022/06/14 20:31:47 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	Base * p;
	Base * p1;

	p = generate();
	usleep(1000000);
	p1 = generate();

	std::cout << "POINTER" << std::endl;
	identify(p);
	identify(p1);

	std::cout << "REFERENCE" << std::endl;
	identify(*p);
	identify(*p1);

	delete p;
	delete p1;
	return (0);
}
