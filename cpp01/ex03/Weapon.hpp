/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:35:35 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/14 22:35:36 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

#define	WEAPON_HPP

#include <string>
#include <iostream>


class Weapon
{
	private:
			std::string	_type;
	public:
			const std::string& getType(void);
			void	setType(std::string type);
			Weapon(std::string type);
			~Weapon(void);
};

#endif