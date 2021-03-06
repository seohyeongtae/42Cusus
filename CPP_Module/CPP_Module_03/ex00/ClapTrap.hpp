/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:21:25 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/15 18:00:03 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	Hitpoints;
	unsigned int	energy;
	unsigned int	damage;
public:
	void			attack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	unsigned int	getDamage();
	void			setDamage(unsigned int damage);

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & clap);
	~ClapTrap();

	ClapTrap &	operator=(ClapTrap const & clap);
};

#endif