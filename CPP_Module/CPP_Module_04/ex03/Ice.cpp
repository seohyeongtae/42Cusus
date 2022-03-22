/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:35:33 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 18:52:18 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

	AMateria * Ice::clone() const
	{
		return (new Ice());
	}

	void	Ice::use(const ICharacter & target)
	{
		std::cout << "Shoots an ice bolt at " << target.getName() << std::endl;
	}

	Ice::Ice() : AMateria("ice")
	{
		std::cout << "Ice Constructor Called" << std::endl;
	}

	Ice::Ice(const std::string& type) : AMateria(type)
	{
		std::cout << "Ice Constructor Called With name" << std::endl;
	}

	Ice::Ice(const Ice & i)
	{
		this->type = i.type;
		std::cout << "Ice Copy Constructor Called" << std::endl;
	}

	Ice & Ice::operator=(const Ice& i)
	{
		this->type = i.type;
		std::cout << "Ice operator Called" << std::endl;
		return (*this);
	}

	Ice::~Ice()
	{
		std::cout << "Ice Destructor Called" << std::endl;
	}
	