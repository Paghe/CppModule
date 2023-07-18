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

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    Zombie* Horde;

    Horde = zombieHorde(8, "horde");
    for (int i = 0; i < 8; i++)
        Horde->announce();
    delete[] Horde;
    return (0);
}