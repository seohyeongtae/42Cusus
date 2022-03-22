/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:40:30 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 19:00:00 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        Materia[i] = NULL;
    std::cout << "MateriaSource Constructor Called" << std::endl;
}

AMateria * MateriaSource::getMateria(int idx) const
{
    return (Materia[idx]);
}

void    MateriaSource::learnMateria(AMateria* m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (Materia[i] == NULL)
            {
                Materia[i] = m;
                std::cout << "MateriaSource learnMateria Success " <<  m->getType() <<std::endl;
                return;
            }
        }
    }
    std::cout << "MateriaSource learnMateria fail" << std::endl;
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (Materia[i] && Materia[i]->getType() == type)
        {
            std::cout << "MateriaSource createMateria Success " <<  Materia[i]->getType() <<std::endl;
            return Materia[i]->clone();
        }
    }
    std::cout << "MateriaSource createMateria fail " << std::endl;
    return NULL;
}

MateriaSource::MateriaSource(const MateriaSource& m)
{
    AMateria *temp;
	for (int i = 0; i < 4; i++)
	{
		if (Materia[i])
		{
			delete Materia[i];
			Materia[i] = NULL;
		}
		temp = m.getMateria(i);
        if (temp)
            {
				Materia[i] = temp->clone();
                delete temp;
                temp = NULL;
            }
	}
    std::cout << "MateriaSource Copy Constructor Called" << std::endl;
}

MateriaSource & MateriaSource::operator=(const MateriaSource& m)
{
    if (this != &m)
	{
		AMateria *temp;
		for (int i = 0; i < 4; i++)
		{
			if (Materia[i])
			{
				delete Materia[i];
				Materia[i] = NULL;
			}
			temp = m.getMateria(i);
			if (temp)
            {
				Materia[i] = temp->clone();
                delete temp;
                temp = NULL;
            }
		}
	}
    std::cout << "MateriaSource operator Called" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete Materia[i];
        Materia[i] = NULL;
    }
    std::cout << "MateriaSource Destructor Called" << std::endl;
}
