/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:51:07 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 21:03:52 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WROGNANIMAL_HPP
# define WROGNANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(WrongAnimal const &ani);
	void setType(std::string const name);
	std::string getType() const;
	void	makeSound() const;
	WrongAnimal & operator = (WrongAnimal const &ani);
	virtual ~WrongAnimal();
};

#endif