/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:46:47 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/13 15:19:29 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string*    stringPTR = &str;
    std::string&    stringREF = str;
    std::cout   <<	"ADDRESS str: " << &str << std::endl 
                <<	"ADDRESS stringPTR: " << stringPTR << std::endl	
                <<	"ADDRESS stringGREF: " << &stringREF << std::endl
				<<	"VALUE str: " << str << std::endl 
                <<	"VALUE stringPTR: " << *stringPTR << std::endl	
                <<	"VALUE stringREF: " << stringREF << std::endl;
}
