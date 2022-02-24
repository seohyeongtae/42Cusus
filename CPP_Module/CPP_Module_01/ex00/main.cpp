/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:00:39 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/24 20:32:51 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z1;
	Zombie	*z2;
	Zombie	z3("dddddd");

	z3.announce();
	z1 = new Zombie("zombie1");
	z2 = new Zombie("zombie2");

	randomChump("zombie3");
	z1->announce();
	z2->announce();
	Zombie *z4 = newZombie("zombie4");
	z4->announce();
		
	delete z1;
	delete z2;
	delete z4;
	return (0);
}
