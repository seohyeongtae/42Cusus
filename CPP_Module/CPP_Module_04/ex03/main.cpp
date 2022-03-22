/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:40:01 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 18:57:48 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src1 = new MateriaSource();
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());

	ICharacter* me1 = new Character("me");
	AMateria* tmp0;
	tmp0 = src1->createMateria("ice");
	me1->equip(tmp0);
	tmp0 = src1->createMateria("cure");
	me1->equip(tmp0);

	std::cout << "\033[1;33m" << std::endl;
	
	ICharacter* bob1 = new Character("bob");

	me1->use(0, *bob1);
	me1->use(1, *bob1);

	delete bob1;
	delete me1;
	delete src1;
	
	std::cout << "\033[0;35m" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(NULL);
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << "\033[0;32m" << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("icecure");

	ICharacter* me = new Character("me");
	ICharacter* bob = new  Character("bob");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\033[0;31m" << std::endl;

	AMateria* tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	AMateria* tmp2 = src->createMateria("cure");
	me->equip(tmp);


	std::cout << "\033[1;33m"<< std::endl;
	
	me->unequip(2);
	me->unequip(3);

	bob->equip(tmp1);
	bob->equip(tmp2);

	me->use(0, *bob);
	me->use(1, *bob);

	bob->use(0, *me);
	bob->use(1, *me);

	delete bob;
	delete me;
	delete src;
  
	return (0);
}
