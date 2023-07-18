/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:15:07 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/12 15:45:53 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
  private:
            std::string name;            
  public:  
            Zombie(std::string getName);
            Zombie(void);
            void  setName(std::string name);
            ~Zombie(void);
            void    announce(void);
};

#endif