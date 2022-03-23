/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:06:56 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/23 21:59:57 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria *Materia[4];
	std::string	name;
public:
	Character();
	std::string const & getName() const;
	AMateria * getMateria(int n) const;
	void	equip(AMateria* m);
	void	delMateria(AMateria* dm);
	void	unequip(int idx);
	void	use(int idx, ICharacter & target);

	Character(const Character &c);
	Character(const std::string& name);
	Character& operator=(const Character& c);
	virtual ~Character();
};
#endif
