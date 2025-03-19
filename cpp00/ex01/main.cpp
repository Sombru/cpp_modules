/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:32:18 by pkostura          #+#    #+#             */
/*   Updated: 2025/03/19 11:55:10 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".includes.hpp"

int main()
{
    // Create a Contact object
    Contact contact;

    std::string input;
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    contact.set_first_name(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contact.set_last_name(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contact.set_number(input);

    // Retrieve and display values using getters
    std::cout << "\nContact Details:" << std::endl;
    std::cout << "First Name: " << contact.get_first_name() << std::endl;
    std::cout << "Last Name: " << contact.get_last_name() << std::endl;
    std::cout << "Phone Number: " << contact.get_number() << std::endl;

	// destructor is called automaticaly for stack allocated objects
}