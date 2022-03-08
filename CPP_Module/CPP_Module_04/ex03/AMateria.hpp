/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:10:15 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/08 02:48:51 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATRRIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
private:
	std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	~AMateria();
};

#endif