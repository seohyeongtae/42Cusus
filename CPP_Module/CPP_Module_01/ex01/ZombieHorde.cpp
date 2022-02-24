/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:46:57 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/24 01:10:46 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>


Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombiearr;
	std::stringstream ss;

	zombiearr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		ss.str(std::string());
		ss << name << " " << i;
		zombiearr[i].setName(ss.str());
	}
	return zombiearr;
}
