/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:18:16 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/24 21:34:04 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {

}

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon(void) {
	
}

void Weapon::setType(const std::string &type) {
	this->type = type;
}

const std::string &Weapon::getType(void) {
	return this->type;
}
