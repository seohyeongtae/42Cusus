/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 01:55:28 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/25 02:38:09 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void) {
	
}
Karen::~Karen(void) {
	
}
void	Karen::complain(std::string level) {
	void	(Karen::*f[5])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error,
		&Karen::wrong
	};
	std::string message[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		if (level == message[i])
		{
			cnt = i + 1;
			std::cout << "[ " << message[i] << " ] " << std::endl;
		}
	}
	switch (cnt)
	{
	case 0:
		(this->*(f[4]))();
		break;
	case 1:
		(this->*(f[0]))();
		break;
	case 2:
		(this->*(f[1]))();
		break;
	case 3:
		(this->*(f[2]))();
		break;
	case 4:
		(this->*(f[3]))();
		break;
	default:
		break;
	}
}

void	Karen::debug(void) {	
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info(void) {
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void) {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;	
}

void	Karen::wrong(void) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
