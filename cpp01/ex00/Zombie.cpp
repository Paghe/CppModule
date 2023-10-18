/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:22:00 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/11 15:06:28 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie(void)
{
    std::cout << this->_name
                << ": destoyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout  << this->_name
                << ": BraiiiiiiinnnzzzZ..." << std::endl;
}