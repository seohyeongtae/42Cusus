/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:49:38 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 19:31:04 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
 { std::cout << "ShrubberyCreationForm Constructor Called" << std::endl; };

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : Form(s){};

void    ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
    if (b.getGrade() > getSignGrade() || b.getGrade() > getExecGrade())
        throw(GradeTooLowException());
    else
    {
        std::ofstream out("<" + b.getName() + ">_shrubbery",
                    std::ofstream::out | std::ofstream::trunc);
        if (!out.good())
            throw FileException();
        
        std::string shrubbery = 
                                "       ,,,.   \n"
                                "    ,&%%&%&&%,\n"
                                "   ,%&\\%&&%&&%\n"
                                "   %&&%&%&/%&&%\n"
                                "   %&&%/ %&%%&&'\n"
                                "   `&%\\ ` /%&''\n"
                                "       |o|     \n"
                                "       |.|    \n"
                                "  \\\\/ ._\\//";
        out << shrubbery;
        out.close();
    }
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& s)
{
     return *(dynamic_cast<ShrubberyCreationForm*>(&(Form::operator=(s))));
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;};
