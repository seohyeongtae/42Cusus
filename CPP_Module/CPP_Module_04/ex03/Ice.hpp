/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:15:51 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 18:52:10 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	
	AMateria * clone() const;
	void	use(const ICharacter& target);
	Ice(const Ice & i);
	Ice(const std::string& type);
	Ice& operator=(const Ice& i);
	virtual ~Ice();
};

#endif