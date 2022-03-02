/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:08:49 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/02 20:55:00 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
# define Blue "\e[34m"
# define reset "\e[0m"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(ScavTrap &scav);
	ScavTrap(std::string name);

	ScavTrap &	operator = (ScavTrap const & scav);
	void		guardGate();
	void		attack(std::string const & target);

	~ScavTrap();
};
#endif