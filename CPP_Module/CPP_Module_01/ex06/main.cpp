/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 02:06:02 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/25 02:26:51 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char** argv) {
    Karen k;

    if (argc != 2 || std::strlen(argv[1]) == 0)
    {
      std::cout << "please input ./karenFilter log_level " << std::endl;
      return (1);
    }
    k.complain(argv[1]);
    return (0);
}