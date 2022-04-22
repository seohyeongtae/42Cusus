/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:42:45 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 15:42:08 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void b_call(Bureaucrat& b, int& (Bureaucrat::*f)(void)) {
  try {
    // (*(const_cast<Bureaucrat*>(&b)).*f)();
    (b.*f)();
    std::cout << b << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void b_make(const std::string& name, const int& grade) {
  try {
    Bureaucrat b(name, grade);
    std::cout << b << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
int main(void) {
  Bureaucrat j("test", 1);
  Bureaucrat h("test2", 150);

  std::cout << j << std::endl
    << h << std::endl;
  std::cout <<  "\033[0;32m" <<  std::endl;
  b_call(j, &Bureaucrat::incrementGrade);
  b_call(h, &Bureaucrat::decrementGrade);
  std::cout <<  "\033[0;33m" << std::endl;
  b_make("test", 0);
  b_make("test2", 151);
  std::cout << std::endl;
  b_make("test", 70);
  b_make("test2", 70);
  std::cout << "\033[0;35m" <<  std::endl;
  b_call(j, &Bureaucrat::decrementGrade);
  b_call(h, &Bureaucrat::incrementGrade);
  std::cout << "\033[0;31m" <<  std::endl;
  b_call(j, &Bureaucrat::decrementGrade);
  b_call(h, &Bureaucrat::incrementGrade);
  return 0;
}
