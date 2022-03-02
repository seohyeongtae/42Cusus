/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:49:33 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/02 23:40:59 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
# define Green "\e[32m"
# define reset "\e[0m"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string		name;
public:
	DiamondTrap();
	DiamondTrap(DiamondTrap &dia);
	DiamondTrap(std::string name);

	DiamondTrap &	operator = (DiamondTrap const & dia);
	void			attack(std::string const & target);
	void			whoAmI();
	~DiamondTrap();
};
#endif