/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:47:15 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/24 21:10:06 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (weapon)
    	std::cout << name << "  B is attack with  "  << weapon->getType() << std::endl; 
	else
		std::cout << " B has no weapon" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << name << "  B is destroyed.. " << std::endl;
}
