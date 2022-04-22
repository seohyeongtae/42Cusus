/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:49:44 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 20:42:21 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& s);
	ShrubberyCreationForm(const std::string targetName);
	void execute(const Bureaucrat& b) const;
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
	~ShrubberyCreationForm();
};

#endif