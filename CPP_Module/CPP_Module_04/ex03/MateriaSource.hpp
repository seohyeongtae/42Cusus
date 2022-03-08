/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:38:19 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/08 02:48:52 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	/* data */
public:
	MateriaSource(/* args */);
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
	~MateriaSource();
};

#endif