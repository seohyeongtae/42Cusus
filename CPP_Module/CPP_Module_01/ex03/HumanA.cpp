/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:06:46 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/25 17:27:22 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

void	HumanA::attack(void)
{
    std::cout << name << "  A is attack with  "  << weapon.getType() << std::endl; 
}

HumanA::~HumanA(void)
{
    std::cout << name << "  A is destroyed.. " << std::endl;
}
