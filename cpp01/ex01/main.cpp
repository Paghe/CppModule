/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:19:50 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/12 15:00:23 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* Horde;

    Horde = zombieHorde(8, "horde");
	std::cout << "This is idx 0 ";
	Horde[0].announce();
	std::cout << "This is idx 7 ";
	Horde[7].announce();
	std::cout << "This is out of range -> ";
	Horde[8].announce();
    delete[] Horde;
    return (0);
}