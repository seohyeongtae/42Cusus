/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:15:15 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 23:47:03 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{

    // const Animal* i = new Cat();
    // const Animal* j = new Dog();
    // const Animal* k = new Dog();

    // std::cout << std::endl;
    // i->makeSound();
    // j->makeSound();
    // std::cout << std::endl;
    // *(const_cast<Animal*>(k)) = *(const_cast<Animal*>(j));
    // std::cout << std::endl;
    // k->makeSound();
    // std::cout << std::endl;

    // delete k;
    // delete j;
    // delete i;

    Animal* meta[100 / 5];
    Dog*  collie;

    for (int i = 0 ; i < 100 / 5 ; ++i) {
        if (!(i % 2)) {
        meta[i] = new Cat();
        } else {
        meta[i] = new Dog();
        }
    }
    collie = new Dog((*dynamic_cast<Dog *>(meta[1])));
    for (int i = 0 ; i < 100 / 5 ; ++i)
        delete meta[i];
    std::cout << collie->getBrain()->getIdeas;
    delete collie;
}