/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:46:18 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 17:25:41 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : sign_grade(0), exec_grade(0)
 { std::cout << "Form Constructor Called" << std::endl; };

Form::Form(const std::string& name, const int& sign_grade, const int& exec_grade)
: name(name), sign_grade(sign_grade), exec_grade(exec_grade), sign(false)
{
	if (sign_grade <= 0 || exec_grade <= 0)
		throw(GradeTooHighException());
	else if (sign_grade > 150 || exec_grade > 150)
		throw(GradeTooLowException());
}

Form::Form(const Form& f) 
: name(f.getName()), sign_grade(f.getSignGrade()), exec_grade(f.getExecGrade()), sign(false)
{
	if (sign_grade <= 0 || exec_grade <= 0)
		throw(GradeTooHighException());
	else if (sign_grade > 150 || exec_grade > 150)
		throw(GradeTooLowException());
}

const std::string& Form::getName() const
{
	return name;
}

const bool& Form::getSign() const
{
	return sign;
}

const int& Form::getSignGrade() const
{
	return sign_grade;
}

const int& Form::getExecGrade() const
{
	return exec_grade;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > sign_grade)
		throw(GradeTooLowException());
	else
		sign = true;
}

Form& Form::operator= (const Form& f)
{
	if (this != &f) {
		*(const_cast<std::string*>(&name)) = f.getName();
		*(const_cast<int*>(&sign_grade)) = f.getSignGrade();
		*(const_cast<int*>(&exec_grade)) = f.getExecGrade();
		sign = f.getSign();
	}
	return *this;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
    return ("GradeTooHighException");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("GradeTooLowException");
}

Form::~Form() {std::cout << "Form Destructor Called" << std::endl;};

std::ostream& operator<<(std::ostream& o, const Form& f) {
  return o << "<" << f.getName() << ">, sign grade <"
          << f.getSignGrade() << ">, exec grade <"
          << f.getExecGrade() << ">, signed <"
          << std::boolalpha << f.getSign() << ">";
}
