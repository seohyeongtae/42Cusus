/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:31:03 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 23:22:28 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *attribute;
public:
	Cat();
	Cat(Cat const &d);
	virtual void	makeSound() const;
	Brain	*getBrain() const;
	Cat	& operator= (Cat const &c);
	virtual ~Cat();
};

#endif