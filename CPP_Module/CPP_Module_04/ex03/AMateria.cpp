/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:12:34 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 18:44:09 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("")
{
	std::cout << "AMateria Constructor Called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria type Constructor Called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(const ICharacter & target)
{
	std::cout << "AMateria use " << target.getName() << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor Called" << std::endl;
}
