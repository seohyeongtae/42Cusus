/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:00:39 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/24 01:13:28 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z1;
	int		N;

	N = 10;
	z1 = zombieHorde(N, "Zombie");

	for (int i = 0; i < N; i++)
		z1[i].announce();
	delete [] z1;
	return (0);
}
