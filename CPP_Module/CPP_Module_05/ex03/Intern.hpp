/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:02:49 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 20:42:46 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern();
	class MatchingErrorException : public std::exception {
	public:
		const char* what() const throw();
	};
	Form* makeForm(std::string formName, std::string targetForm);

	Intern(const Intern& i);
	Intern& operator= (const Intern& i);
	~Intern();
};

#endif