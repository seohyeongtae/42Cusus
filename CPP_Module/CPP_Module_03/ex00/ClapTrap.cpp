/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:21:40 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/02 18:01:23 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "blackhole";
	this->Hitpoints = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << " set name!!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->Hitpoints = 10;
	this->energy = 10;
	this->damage = 0;

	std::cout << "(" << name 
	<< ") ClapTrap constructor created!!" << std::endl; 
}

ClapTrap::ClapTrap(ClapTrap const & clap) : name(clap.name), Hitpoints(clap.Hitpoints), energy(clap.energy), damage(clap.damage)
{
	std::cout << "(" << name 
	<< ") ClapTrap copy constructor called" << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap ("  << name 
	<< ") attack (" << target << "), causing (" 
	<< damage << ") points of damage!" << std:: endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap ("  << name 
	<< ") has taken (" << amount 
	<< ") points of damage!" << std:: endl;
	
	if (Hitpoints == 0)
	{
		std::cout << "(" << name 
		<<  ") already fall in Black Hole" << std::endl;
	}
	else if (this->Hitpoints <= amount)
	{
		Hitpoints = 0;
		std::cout << "ClapTrap" << "(" << name 
		<<  ") You've been absorbed by the Black Hole" << std::endl;
	}
	else
	{
		Hitpoints -= amount;
		std::cout << "ClapTrap ("  << name 
		<< ") HP is now (" << Hitpoints 
		<< ")" << std:: endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (Hitpoints == 0)
	{
		this->Hitpoints = amount;
		std::cout << "ClapTrap (" << name 
		<< ") has Escaped blackhole! " 
		<< amount << " energy points" << std::endl;
	}
	else
	{
		this->Hitpoints += amount;
		std::cout << "ClapTrap " << name 
		<< " has been repaired and is back to life with " 
		<< amount << " energy points" << std::endl;
	}
}

unsigned int	ClapTrap::getDamage()
{
	return (this->damage);
}

void	ClapTrap::setDamage(unsigned int damage)
{
	this->damage = damage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "(" << name 
	<<  ") ClapTrap destructor called" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & clap)
{
	this->name = clap.name;
	this->Hitpoints = clap.Hitpoints;
	this->energy = clap.energy;
	this->damage = clap.damage;
	
	std::cout << "(" << name 
	<< ") ClapTrap operator called" << std::endl;
	return (*this);
}
