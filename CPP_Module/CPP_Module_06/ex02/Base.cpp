/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:14:05 by hyseo             #+#    #+#             */
/*   Updated: 2022/06/14 20:28:49 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate()
{
    std::srand((unsigned int)time(NULL));
    int randNum = std::rand() + 1;
    Base* base = NULL;
    try 
    {
        if (randNum % 3 == 1)
            base = dynamic_cast<Base *>(new A);
        else if (randNum % 3 == 2)
            base = dynamic_cast<Base *>(new B);
        else if (randNum % 3 == 0)
            base = dynamic_cast<Base *>(new C);
        return (base);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return(NULL);
    }
    
}

void identify(Base* b)
{
    try
	{
		if (dynamic_cast<A *>(b))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(b))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(b))
			std::cout << "C" << "\n";
	}
	catch(const std::exception& e)
    {
		std::cerr << e.what() << '\n';
    }

}
void identify(Base& b)
{
    try
	{
		if (dynamic_cast<A *>(&b))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(&b))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(&b))
			std::cout << "C" << "\n";
	}
	catch(const std::exception& e)
    {
		std::cerr << e.what() << '\n';
    }
}

