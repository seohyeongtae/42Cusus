/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:02:44 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 20:55:21 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern()
 { std::cout << "Intern Constructor Called" << std::endl; };


Intern::Intern(const Intern& i) { static_cast<void>(i); }

Form* Intern::makeForm(std::string formName, std::string targetForm)
{
	std::string literals[3] = {"robotomy request", "shrubbery creation" , "presidential pardon" };
	try {
		for (int i = 0; i < 3; i++)
		{
			if(literals[i] == formName)
			{
				switch(i)
				{
					case 0 :
						return new RobotomyRequestForm(targetForm);
						break;
					case 1 :
						return new ShrubberyCreationForm(targetForm);
						break;
					case 2 :
						return new PresidentialPardonForm(targetForm);
						break;
				}
			}
		}
		std::cout << "(some explicit error message)" << std::endl;
		throw MatchingErrorException();

	} catch (std::exception& e) {
		std::cout << "Intern cannot create <" << targetForm << ">" << "because <" << e.what() << ">" << std::endl;
	}
	return NULL;
}

const char* Intern::MatchingErrorException::what() const throw() {
	return ("MatchingErrorException");
};

Intern& Intern::operator=(const Intern& i) {
  static_cast<void>(i);
  return *this;
}

Intern::~Intern()
{ std::cout << "Intern Destructor Called" << std::endl; };

// class Intern {
// public:
// 	Intern();
// 	class MatchingErrorException : public std::exception {
// 	public:
// 		const char* what() const throw();
// 	};
// 	Form* makeForm(std::string formName, std::string targetForm);

// 	Intern(const Intern& i);
// 	Intern& operator= (const Intern& i);
// 	~Intern();
// }