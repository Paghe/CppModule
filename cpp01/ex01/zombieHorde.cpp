/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:08:47 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/12 15:42:46 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombieHeap = new Zombie[N];
    for(int i = 0; i < N; i++)
            zombieHeap[i].setName(name);
    return (zombieHeap);  
}