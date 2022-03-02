/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:21:19 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/02 18:03:40 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("a");
	ClapTrap	b("hyseo");
	ClapTrap	c("CPP Moudule");

	a.setDamage(5);
	b.setDamage(10);
	c.setDamage(5);

	std::cout << std::endl;
	a.attack("hyseo");
	b.takeDamage(a.getDamage());
	std::cout << std::endl;

	b.attack("a");
	a.takeDamage(b.getDamage());
	std::cout << std::endl;

	b.beRepaired(3);
	c.attack("hyseo");
	b.takeDamage(c.getDamage());
	std::cout << std::endl;


	a.beRepaired(25);
	std::cout << std::endl;
	return (0);
}
