/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:31:03 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/08 00:49:37 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *attribute;
public:
	Dog();
	Dog(Dog const &d);
	virtual void	makeSound() const;
	const Brain	*getBrain() const;
	Dog	& operator= (Dog const &d);
	virtual ~Dog();
};

#endif
