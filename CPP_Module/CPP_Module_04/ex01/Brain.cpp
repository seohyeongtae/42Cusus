/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:44:17 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 23:18:47 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << "Ideas  ";
		ss << i;
		this->ideas[i] = ss.str();
	}
	std::cout << "Brain Constructor Called" << std::endl;
}
Brain::Brain(Brain const &b)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = b.ideas[i];
	}
	std::cout << "Brain Copy Constructor Called" << std::endl;
}

void	Brain::setIdeas(const int &i, const std::string &idea)
{
	this->ideas[i] = idea;
}

std::string	Brain::getIdeas(const int &i) const
{
	return (this->ideas[i]);
} 

Brain	& Brain::operator=(Brain const &b)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = b.ideas[i];
	}
	std::cout << "Brain operator Called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called" << std::endl;
}