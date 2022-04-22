/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:49:17 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 20:35:54 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5)
 { std::cout << "PresidentialPardonForm Constructor Called" << std::endl; };
 
PresidentialPardonForm::PresidentialPardonForm(const std::string targetName)
: Form(targetName, 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s) : Form(s){};

void    PresidentialPardonForm::execute(const Bureaucrat& b) const
{
    if (b.getGrade() > getSignGrade() || b.getGrade() > getExecGrade())
        throw(GradeTooLowException());
    else
        std::cout << "<" << b.getName() << "> has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& s)
{
     return *(dynamic_cast<PresidentialPardonForm*>(&(Form::operator=(s))));
}

PresidentialPardonForm::~PresidentialPardonForm()
{std::cout << "RobotomyRequestForm Destructor Called" << std::endl;};
