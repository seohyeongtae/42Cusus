/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:15:15 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 15:43:51 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{

    const Animal* i = new Cat();
    const Animal* j = new Dog();
    const Animal* k = new Dog();

    std::cout << std::endl;
    i->makeSound();
    j->makeSound();
    std::cout << std::endl;
    *(const_cast<Animal*>(k)) = *(const_cast<Animal*>(j));
    std::cout << std::endl;
    k->makeSound();
    std::cout << std::endl;

    delete k;
    delete j;
    delete i;

    std::cout << std::endl << std::endl;
    Animal* meta[20];
    Dog*  tmp_dog;
    Cat*  tmp_cat;

    for (int a = 0 ; a < 20 ; a++) {
        if (!(a % 2)) {
        meta[a] = new Cat();
        meta[a]->setType("Cat");
        } else {
        meta[a] = new Dog();
        }
    }
    std::cout << std::endl;
    for (int a = 0 ; a < 20 ; a++)
    {
        if (!(a % 2))
        {
            std::cout << "\033[1;33m";
            tmp_cat = dynamic_cast<Cat *>(meta[a]);
            std::cout << (tmp_cat->getBrain())->getIdeas(a) 
            << "  Type = " << tmp_cat->getType()<< std::endl;
        }
        else 
        {
            std::cout << "\033[1;34m";
            tmp_dog = dynamic_cast<Dog *>(meta[a]);
            std::cout << (tmp_dog->getBrain())->getIdeas(a) 
            << "  Type = " << tmp_dog->getType()<< std::endl;
        }
        delete meta[a];
    }
}
