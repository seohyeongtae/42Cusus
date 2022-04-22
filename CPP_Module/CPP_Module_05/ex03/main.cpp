/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:42:45 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 20:57:59 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void) {
  Intern i;
  Bureaucrat b1("teset1", 1);
  Bureaucrat b2("test2", 15);
  Bureaucrat b3("test3", 70);
  Bureaucrat b4("test4", 140);

  Form* f1 = i.makeForm("presidential pardon", "Form1");
  Form* f2 = i.makeForm("robotomy request", "Form2");
  Form* f3 = i.makeForm("shrubbery creation", "Form3");
  i.makeForm("Something Wrong", "NOT GONNAE GENERATED");

  if (!f1 || !f2 || !f3)
    return (1);
  std::cout << std::endl;
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
  std::cout <<  "\033[0;32m" <<  std::endl;
  b2.signForm(*f1);
  b3.signForm(*f2);
  b4.signForm(*f3);
  std::cout << std::endl;
  std::cout <<  "\033[0;33m" <<  std::endl;
  b3.executeForm(*f1);
  b3.executeForm(*f2);
  b3.executeForm(*f3);
  std::cout << std::endl;
  std::cout <<  "\033[0;34m" <<  std::endl;
  b1.executeForm(*f1);
  b1.executeForm(*f2);
  b1.executeForm(*f3);
  std::cout <<  "\033[0;35m" <<  std::endl;
  delete f3;
  delete f2;
  delete f1;
  return 0;
}