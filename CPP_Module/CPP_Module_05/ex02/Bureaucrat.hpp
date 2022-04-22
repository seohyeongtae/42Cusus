/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:42:20 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 19:09:18 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Form;

class Bureaucrat {
private:
    const std::string   name;
    int                 grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const int &grade);
    Bureaucrat(const Bureaucrat &b);

    class GradeTooHighException : public std::exception {
    public :
        const char* what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
    public :
        const char* what(void) const throw();
    };

    const std::string   getName() const;
    const int           getGrade() const;
    int&                incrementGrade();
    int&                decrementGrade();
    void                signForm(const Form& f) const;
    void                executeForm(const Form& f) const;
    
    Bureaucrat &operator = (const Bureaucrat &b);
    ~Bureaucrat();
};

std::ostream& operator << (std::ostream& o, const Bureaucrat& b);

#endif