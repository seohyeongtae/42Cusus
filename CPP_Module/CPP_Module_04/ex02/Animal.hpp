/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:16:37 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/08 00:55:05 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(std::string name);
	Animal(Animal const &ani);
	void setType(std::string const name);
	std::string getType() const;
	virtual void	makeSound() const = 0;
	Animal & operator = (Animal const &ani);
	virtual ~Animal();
};

#endif