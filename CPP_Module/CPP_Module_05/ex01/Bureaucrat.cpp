/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:42:36 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 17:27:32 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() { std::cout << "Bureaucrat Constructor Called" << std::endl; }

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : name(name), grade(grade) {
    if (grade <= 0)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.getName()), grade(b.getGrade())
{
    if (grade <= 0)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &b)
{
    if (this != &b)
    {
        *(const_cast<std::string *>(&this->name)) = b.getName();
        grade = b.getGrade();
    }
    return (*this);
}

const std::string  Bureaucrat::getName() const
{
    return name;
}

const int   Bureaucrat::getGrade() const
{
    return grade;
}

int&    Bureaucrat::incrementGrade()
{
    if (grade - 1 <= 0)
    {
        throw(GradeTooHighException());
    } else
        grade -= 1;
    return grade;
}

int&    Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
    {
        throw(GradeTooLowException());
    } else
        grade += 1;
    return grade;
}

void    Bureaucrat::signForm(const Form& f) const 
{
    try{
        (*const_cast<Form*>(&f)).beSigned(*this);
        std::cout << "<bureaucrat> signed <" << f.getName() << ">" << std::endl;
    } catch(std::exception& e)
    {
        std::cout << "<bureaucrat> couldn’t sign <form> because <" << e.what() << ">" << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("GradeTooLowException");
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat Destructor Called" << std::endl; }

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
  return o << "<" << b.getName() << ">, bureaucrat grade <" << b.getGrade() << ">";
}
