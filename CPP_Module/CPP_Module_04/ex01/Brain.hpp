/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:19:28 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 23:18:34 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain(Brain const &b);
	void	setIdeas(const int &i, const std::string &idea);
	std::string	getIdeas(const int &i) const;
	Brain & operator=(Brain const &b);
	~Brain();
};

#endif