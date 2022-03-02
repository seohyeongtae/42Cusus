/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:06:00 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/02 23:11:42 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
# define Yellow "\e[33m"
# define reset "\e[0m"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(FragTrap &frag);
	FragTrap(std::string name);

	FragTrap &	operator = (FragTrap const & scav);
	void		highFivesGuys();
	
	~FragTrap();
};
#endif