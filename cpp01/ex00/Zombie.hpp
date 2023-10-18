/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:22:03 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/11 15:27:49 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
  private:
            std::string _name;
  public:
            Zombie(std::string name);
			~Zombie(void);
            void    announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
#endif