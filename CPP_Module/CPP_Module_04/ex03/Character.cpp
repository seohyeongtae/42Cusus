/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:38:09 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 19:01:09 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter(), name("")
{
	for (int i = 0; i < 4; i++)
		Materia[i] = NULL;
	std::cout << "Character Constructor Called" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->name);
}
AMateria * Character::getMateria(int n) const
{
	return (Materia[n]);
}

void	Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (Materia[i] == NULL)
			{
				Materia[i] = m;
				std::cout << "Character equip " << m->getType() << std::endl;
				return;
			}
		}
	}
	std::cout << "Character equip Fail"<< std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
	{
		if (Materia[idx] != NULL)
		{
			Materia[idx] = NULL;
			std::cout << "Character unequip success" << std::endl;
			return;
		}
	}
	std::cout << "Character unequip Fail" << std::endl;
}

void	Character::use(int idx, ICharacter & target)
{
	if (Materia[idx] != NULL)
	{
		Materia[idx]->use(target);
	}
	std::cout << "Character Use Fail" << std::endl;
}

Character::Character(const Character &c)
{
	AMateria *temp;
	for (int i = 0; i < 4; i++)
	{
		if (Materia[i])
		{
			delete Materia[i];
			Materia[i] = NULL;
		}
		temp = c.getMateria(i);
		if (temp)
			{
				Materia[i] = temp->clone();
				delete temp;
				temp = NULL;
			}
	}
	std::cout << "Character Copy Constructor Called" << std::endl;
}

Character::Character(const std::string& name) : ICharacter(), name(name)
{
	for (int i = 0; i < 4; i++)
		Materia[i] = NULL;
	std::cout << "Character Constructor Called With name" << std::endl;
}

Character & Character::operator=(const Character& c)
{
	if (this != &c)
	{
		name = c.getName();
		AMateria *temp;
		for (int i = 0; i < 4; i++)
		{
			if (Materia[i])
			{
				delete Materia[i];
				Materia[i] = NULL;
			}
			temp = c.getMateria(i);
			if (temp)
			{
				Materia[i] = temp->clone();
				delete temp;
				temp = NULL;
			}
		}
		return (*this);
	}
	std::cout << "Character operator Called" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete Materia[i];
		Materia[i] = NULL;
	}
	std::cout << "Character Destructor Called" << std::endl;
}
