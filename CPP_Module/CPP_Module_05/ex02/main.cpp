/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:42:45 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 19:34:37 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat b1("test1", 1);
  Bureaucrat b2("test2", 15);
  Bureaucrat b3("test3", 70);
  Bureaucrat b4("test4", 140);

  Form*f1 = new PresidentialPardonForm();
  Form*f2 = new RobotomyRequestForm();
  Form*f3 = new ShrubberyCreationForm();

  std::cout << b1 << std::endl
    << b2 << std::endl
    << b3 << std::endl
    << b4 << std::endl;
  std::cout << std::endl;
  std::cout <<  "\033[0;31m" <<  std::endl;
  std::cout << *f1 << std::endl
    << *f2 << std::endl
    << *f3 << std::endl;
  std::cout << std::endl;
  std::cout <<  "\033[0;32m" << std::endl;
  b2.signForm(*f1);
  b3.signForm(*f2);
  b4.signForm(*f3);
  std::cout <<  "\033[0;34m" << std::endl;
  std::cout << std::endl;
  b2.executeForm(*f1);
  b3.executeForm(*f2);
  b4.executeForm(*f3);
  std::cout <<  "\033[0;35m" << std::endl;
  std::cout << std::endl;
  b1.executeForm(*f1);
  b1.executeForm(*f2);
  b1.executeForm(*f3);
  std::cout <<  "\033[0;36m" << std::endl;
  delete f3;
  delete f2;
  delete f1;
  return 0;
}
