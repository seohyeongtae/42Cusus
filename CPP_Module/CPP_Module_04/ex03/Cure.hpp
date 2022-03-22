/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:23:38 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 18:46:12 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	
	AMateria * clone() const;
	void	use(const ICharacter& target);
	Cure(const Cure & c);
	Cure(const std::string& type);
	Cure& operator=(const Cure& c);
	virtual ~Cure();
};

#endif