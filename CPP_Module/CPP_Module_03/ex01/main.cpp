/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:21:19 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/02 20:45:40 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("a");
	ScavTrap	b("b");

	std::cout << std::endl;
	
	a.attack("b");
	b.takeDamage(a.getDamage());
	
	std::cout << std::endl;
	
	b.attack("a");
	a.takeDamage(b.getDamage());
	
	std::cout << std::endl;
	
	a.attack("b");
	b.takeDamage(a.getDamage());
	
	std::cout << std::endl;
	
	b.attack("a");
	a.takeDamage(b.getDamage());
	
	std::cout << std::endl;
	
	b.guardGate();
	
	std::cout << std::endl;
	return (0);
}
