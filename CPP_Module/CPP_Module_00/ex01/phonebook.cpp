/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:20:49 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/25 16:00:30 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	phonebook_add(Phonebook *phone, int index)
{
	std::string input;
	Phonebook phonebook = Phonebook();

	std::cout <<"Input First_name" << std::endl;
	getline(std::cin, input);
	phonebook.set_first_name(input);
	std::cout <<"Input Last_name" << std::endl;
	getline(std::cin, input);
	phonebook.set_last_name(input);
	std::cout <<"Input Nick_name" << std::endl;
	getline(std::cin, input);
	phonebook.set_nick_name(input);
	std::cout <<"Input Phone_number" << std::endl;
	getline(std::cin, input);
	phonebook.set_phone_number(input);
	std::cout <<"Secret" << std::endl;
	getline(std::cin, input);
	phonebook.set_secret(input);
	if (index <= 7) 
		phone[index] = phonebook;
	else{
		for (int i = 0; i < 7; i++)
			phone[i] = phone[i + 1];
		phone[7] = phonebook;
	}
	return;
}

void	phonebook_search(Phonebook *phone, int index)
{
	int start = 0;
	int finish = 8;
	std::cout << std::setw(10) << "Index";
	std::cout << " | "; 
	std::cout << std::setw(10) << "First_name";
	std::cout << " | "; 
	std::cout << std::setw(10) << "Last_name";
	std::cout << " | "; 
	std::cout << std::setw(10) << "Nick_name";
	std::cout << " | "; 
	std::cout << std::setw(10) << "Phone_Num";
	std::cout << std::endl;
	if (index == 0) {
		start = 0;
		finish = 8;
	}
	else {
		start = index - 1;
		finish = start + 1;
	}
	for (int i = start; i < finish; i++)
	{
		if (phone[i].get_first_name() != "\0" 
		&& phone[i].get_last_name() != "\0" 
		&& phone[i].get_nick_name() != "\0" 
		&& phone[i].get_phone_number() != "\0")
		{
			std::cout << std::setw(9) << i + 1 << ".";
			std::cout << " | "; 
			std::cout << std::setw(9) << phone[i].get_first_name() << ".";
			std::cout << " | "; 
			std::cout << std::setw(9) << phone[i].get_last_name() << ".";
			std::cout << " | "; 
			std::cout << std::setw(9) << phone[i].get_nick_name() << ".";
			std::cout << " | "; 
			std::cout << std::setw(9) << phone[i].get_phone_number() << ".";
			std::cout << std::endl; 
		}
	}
}

int main(void)
{
	int exit;
	int index;
	int check;

	exit = 1;
	index = 0;
	Phonebook phonebook[8];
	while (exit)
	{
		check = 1;
		std::cout << YELLOW << "\nPlease input command" << GREEN << std::endl;
		std::string str;
		getline(std::cin, str);
		if (str.compare("ADD") == 0) {
			check = 0;
			if (str.length() > 3)
				check = 1;
			else {
				phonebook_add(phonebook, index);
				index++;
			}
		} else if (str.substr(0, 6).compare("SEARCH") == 0) {
			check = 0;
			if(str.length() == 6)
				phonebook_search(phonebook, 0);
			else
				str = str.substr(7, str.length());
			if (str.size() == 1 && str.compare("9") < 0)
				phonebook_search(phonebook, std::stoi(str));
			else if (str.length() > 1 && str.compare("SEARCH") != 0)
				check = 1;
		} else if (str.compare("EXIT") == 0) {
			check = 0;
			std::cout <<"EXIT" << std::endl;
			exit = 0;
		} 
		if (check == 1)
			std::cout << BLUE << "Wrong command" << std::endl;
	}
}
