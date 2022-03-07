/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:50:49 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 21:04:16 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WROGNCAT_HPP
# define WROGNCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat const &d);
	void	makeSound() const;
	WrongCat	& operator= (WrongCat const &c);
	virtual ~WrongCat();
};

#endif