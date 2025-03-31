/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:54:10 by pkostura          #+#    #+#             */
/*   Updated: 2025/03/31 11:48:50 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".includes.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Phonebook constructor\n";
	this->is_running = true;
	this->index = 0;
	this->total_contacts = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destructor\n";
}

void PhoneBook::print_input(const std::string input)
{
	std::cout << input << '\n';
}

void PhoneBook::match_input(const std::string input)
{
	if (!input.compare("ADD") || !input.compare("add"))
		this->add_contact();
	else if ((!input.compare("SEARCH") || !input.compare("search")))
		this->display_contacts();
	else if ((!input.compare("EXIT") || !input.compare("exit")))
	{
		std::cout << "do exit\n";	
		is_running = false;
	}
	else
		std::cout << "invalid command, use: ADD, SEARCH or EXIT\n";
}

void PhoneBook::add_contact()
{
	Contact &current_contact = this->contacts[this->index];

	std::string input;
	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	current_contact.set_first_name(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	current_contact.set_last_name(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	current_contact.set_number(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	current_contact.set_darkest_secret(input);

	std::cout << "Contact added at index " << this->index << ".\n";

	this->index = (this->index + 1) % 8; // Circular buffer logic
	if (this->total_contacts < 8)
		this->total_contacts++;
}


void PhoneBook::display_contacts()
{
    if (this->total_contacts == 0)
    {
        std::cout << "No contacts to display.\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Phone" << "\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < this->total_contacts; i++)
    {
        const Contact &contact = this->contacts[i];
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << contact.get_first_name().substr(0, 10) << "|"
                  << std::setw(10) << contact.get_last_name().substr(0, 10) << "|"
                  << std::setw(10) << contact.get_number().substr(0, 10) << "\n";
    }
}