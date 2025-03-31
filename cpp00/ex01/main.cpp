/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:32:18 by pkostura          #+#    #+#             */
/*   Updated: 2025/03/31 11:39:51 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".includes.hpp"

int main()
{
	PhoneBook phonebook;

	std::cout << "--THIS IS FUNNY PHONEBOOK--\n";
	while (phonebook.is_running == true)
	{
		std::string input;
		std::cout << "Enter a command: ADD, SEARCH or EXIT\n> ";
		std::getline(std::cin, input);
		phonebook.match_input(input);
	}
	
	// destructor is called automaticaly for stack allocated objects
}