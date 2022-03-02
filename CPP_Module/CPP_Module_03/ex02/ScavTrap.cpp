/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:08:56 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/02 21:03:48 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	Hitpoints = 100;
	energy = 50;
	damage = 20;
	std::cout << Blue << "ScavTrap" << " set name!!" << std::endl << reset;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	Hitpoints = 100;
	energy = 50;
	damage = 20;
	std::cout << Blue << "(" << this->name 
	<< ") ScavTrap constructor created!!" << std::endl << reset; 
}

ScavTrap::ScavTrap(ScavTrap &scav) : ClapTrap(scav)
{
	std::cout << Blue << "(" << name 
	<< ") ScavTrap copy constructor called" << std::endl << reset;
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << Blue << "ScavTrap ("  << name 
	<< ") attack (" << target << "), causing (" 
	<< damage << ") points of damage!" << std:: endl << reset;
}

void	ScavTrap::guardGate()
{
	if (Hitpoints != 0) 
	{
		std::cout << Blue << "ScavTrap ("  << name 
		<< ") guardGate mode" << std:: endl << reset;
	}
	else
	{
		std::cout << Blue << "ScavTrap ("  << name 
		<< ") was died" << std:: endl << reset;
	}
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & scav)
{
	this->name = scav.name;
	this->Hitpoints = scav.Hitpoints;
	this->energy = scav.energy;
	this->damage = scav.damage;
	
	std::cout << Blue << "(" << name 
	<< ") ScavTrap operator called" << std::endl << reset;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << Blue << "(" << name 
	<<  ") ScavTrap destructor called" << std::endl << reset;
}
