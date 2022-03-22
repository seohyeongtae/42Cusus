/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:38:19 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 18:15:17 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria * Materia[4];
public:
	MateriaSource();

	AMateria * getMateria(int idx) const;
	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);

	MateriaSource(const MateriaSource& m);
	MateriaSource& operator=(const MateriaSource& m);
	virtual ~MateriaSource();
};

#endif