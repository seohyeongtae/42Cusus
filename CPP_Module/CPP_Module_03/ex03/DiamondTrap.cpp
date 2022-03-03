/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:49:38 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/03 17:48:26 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name(ClapTrap::name)
{
	ClapTrap::name += "_clap_name";
	Hitpoints = FragTrap::Hitpoints;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
	std::cout << Green << "DiamondTrap" << " set name!!" << std::endl << reset;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	this->Hitpoints = FragTrap::Hitpoints;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
	std::cout << Green << "(" << this->name 
	<< ") DiamondTrap constructor created!!" << std::endl << reset; 
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << Green;
	std::cout << "This DiamondTrap name is " << name << " and This ClapTrap name is " << ClapTrap::name << std::endl;
	std::cout << reset;
}

DiamondTrap::DiamondTrap(DiamondTrap &dia) : ClapTrap(dia), ScavTrap(dia), FragTrap(dia)
{
	std::cout << Green << "(" << name 
	<< ") DiamondTrap copy constructor called" << std::endl << reset;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & dia)
{
	ScavTrap::operator=(dia);
	FragTrap::operator=(dia);
	this->name = dia.name;
	std::cout << Green << "(" << name 
	<< ") DiamondTrap operator called" << std::endl << reset;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << Green << "(" << name 
	<<  ") DiamondTrap destructor called" << std::endl << reset;
}
