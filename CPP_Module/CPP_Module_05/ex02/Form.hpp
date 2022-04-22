/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:46:21 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 19:08:24 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class Form {
private:
	const std::string	name;
	bool	sign;
	const int sign_grade;
	const int exec_grade;

public:

Form();
Form(const std::string& name, const int& sign_grade, const int& exec_grade);
Form(const Form & f);
void beSigned(const Bureaucrat& b);
class GradeTooHighException : public std::exception {
    public :
        const char* what(void) const throw();
    };
class GradeTooLowException : public std::exception {
    public :
        const char* what(void) const throw();
    };
class FileException : public std::exception {
    public :
        const char* what(void) const throw();
    };
const std::string& getName() const;
const bool& getSign() const;
const int& getSignGrade() const;
const int& getExecGrade() const;

virtual void execute(const Bureaucrat& b) const = 0;

Form &operator = (const Form &b); 
virtual ~Form();
};

std::ostream& operator<<(std::ostream& o, const Form& f);

#endif