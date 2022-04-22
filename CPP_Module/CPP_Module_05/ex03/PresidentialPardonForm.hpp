/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:49:22 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/22 20:34:45 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& s);
	PresidentialPardonForm(const std::string targetName);
	void execute(const Bureaucrat& b) const;
	PresidentialPardonForm& operator=(const PresidentialPardonForm& s);
	~PresidentialPardonForm();
};

#endif