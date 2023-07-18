/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:21:44 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/11 15:57:49 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    randomChump(std::string name);
Zombie* newZombie(std::string name);

int main(void)
{
    Zombie* Marco;

    Marco = newZombie("MARCO");
    Marco->announce();
    randomChump("Dump");
    delete Marco;
    return (0);
}
