/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:14:55 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/26 20:40:31 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

class Convert {
private:
	const double input;

public:
	Convert();
	Convert(std::string& input);
	Convert(const Convert& c);
	char	to_Char() const;
	int 	to_Int() const;
	float	to_Float() const;
	double	to_Double() const;

	const double	getInput() const;
	Convert& operator=(const Convert& c);
	~Convert();
};

#endif
