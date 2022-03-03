/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:06:07 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/03 16:52:23 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	Hitpoints = 100;
	energy = 100;
	damage = 30;
	std::cout << Yellow << "FragTrap" << " set name!!" << std::endl << reset;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	Hitpoints = 100;
	energy = 100;
	damage = 30;
	std::cout << Yellow << "(" << this->name 
	<< ") FragTrap constructor created!!" << std::endl << reset; 
}

FragTrap::FragTrap(FragTrap &frag) : ClapTrap(frag)
{
	std::cout << Yellow << "(" << name 
	<< ") FragTrap copy constructor called" << std::endl << reset;
}

void	FragTrap::highFivesGuys()
{
	std::cout << Yellow << "(" << name 
	<< ") FragTrap HighFivesGuys!!!" << std::endl << reset;
}

FragTrap &	FragTrap::operator=(FragTrap const & frag)
{
	ClapTrap::operator=(frag);
	
	std::cout << Yellow << "(" << name 
	<< ") FragTrap operator called" << std::endl << reset;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << Yellow << "(" << name 
	<<  ") FragTrap destructor called" << std::endl << reset;
}
