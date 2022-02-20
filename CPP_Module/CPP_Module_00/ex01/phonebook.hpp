/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:48:52 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/20 09:53:31 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

#define YELLOW           "\033[1;33m"
#define GREEN            "\033[0;32m"
#define BLUE             "\033[0;34m"

class Phonebook {
	private : 
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string secret;

	public :
	void set_first_name (std::string first) {
		this->first_name = first;
	}
	void set_last_name (std::string last) {
		this->last_name = last;
	}
	void set_nick_name (std::string nick) {
		this->nick_name = nick;
	}
	void set_phone_number (std::string phone) {
		this->phone_number = phone;
	}
	void set_secret (std::string secret) {
		this->secret = secret;
	}
	
	std::string get_first_name () {
		return this->first_name.substr(0, 9);
	}
	std::string get_last_name () {
		return this->last_name.substr(0, 9);
	}
	std::string get_nick_name () {
		return this->nick_name.substr(0, 9);
	}
	std::string get_phone_number () {
		return this->phone_number.substr(0, 9);
	}
	std::string get_secret () {
		return this->secret.substr(0, 9);
	}
};

#endif