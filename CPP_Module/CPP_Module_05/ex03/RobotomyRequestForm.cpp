/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:49:27 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 20:36:14 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
 { std::cout << "RobotomyRequestForm Constructor Called" << std::endl; };

RobotomyRequestForm::RobotomyRequestForm(const std::string targetName)
: Form(targetName, 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : Form(s){};

void    RobotomyRequestForm::execute(const Bureaucrat& b) const
{
    if (b.getGrade() > getSignGrade() || b.getGrade() > getExecGrade())
        throw(GradeTooLowException());
    else
    {
        std::srand((unsigned int)time(NULL));
        int randNum = std::rand() + 1;
        if (randNum % 2 == 1)
        {
            std::cout << "drrrrrrrrrrrrrrr..." << std::endl;
            std::cout << "<" << b.getName()
            << "> has been robotomized successfully" << std::endl;
        }
        else
        {
            std::cout << "br br br..." << std::endl;
            std::cout << "<" << b.getName() << "> failed to be robotomized" << std::endl;
        }
    }
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& s)
{
     return *(dynamic_cast<RobotomyRequestForm*>(&(Form::operator=(s))));
}

RobotomyRequestForm::~RobotomyRequestForm()
{std::cout << "RobotomyRequestForm Destructor Called" << std::endl;};
