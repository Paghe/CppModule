/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:22:00 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/12 15:46:21 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string getName) : name(getName) {}

Zombie::Zombie(void) {}
void    Zombie::announce(void)
{
    std::cout  << this->name
                << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->name
                << " destoyed" << std::endl;
}