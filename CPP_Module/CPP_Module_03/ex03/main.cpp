/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:21:19 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/15 17:59:03 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a("A");

	std::cout << std::endl;
	a.whoAmI();
	std::cout << std::endl;
	
	{
		DiamondTrap b("B");
		DiamondTrap c("C");


		std::cout << std::endl;
		
		b.whoAmI();
		c.whoAmI();		
		c.highFivesGuys();
		
		std::cout << std::endl;
		
		b.attack("C");
		c.takeDamage(b.getDamage());
		
		std::cout << std::endl;
		
		b.attack("C");
		c.takeDamage(b.getDamage());
		
		std::cout << std::endl;
		
		b.guardGate();
		
		std::cout << std::endl;
	}

	std::cout << std::endl;
	
	DiamondTrap d;
	
	std::cout << std::endl;
	
	d.whoAmI();
	
	std::cout << std::endl;

	d = a;
	
	std::cout << std::endl;
	
	d.whoAmI();
	a.whoAmI();
	
	std::cout << std::endl;
	return (0);
}
