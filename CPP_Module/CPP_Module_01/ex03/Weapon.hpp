/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:11:02 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/24 21:34:05 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string type;
public:
	void setType(const std::string &type);
	const std::string &getType(void);
	Weapon(std::string type);
	Weapon(void);
	~Weapon(void);
};

#endif