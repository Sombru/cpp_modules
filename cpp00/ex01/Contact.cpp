/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:23:17 by pkostura          #+#    #+#             */
/*   Updated: 2025/03/19 11:27:10 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".includes.hpp"

Contact::Contact()
{
	std::cout << "Contact constructor\n";
}

Contact::~Contact()
{
	std::cout << "Contact destructor\n";
}

// Getters
std::string const &Contact::get_first_name() const
{
    return first_name;
}

std::string const &Contact::get_last_name() const
{
    return last_name;
}

std::string const &Contact::get_number() const
{
    return number;
}

// Setters
void Contact::set_first_name(const std::string &name)
{
    first_name = name;
}

void Contact::set_last_name(const std::string &name)
{
    last_name = name;
}

void Contact::set_number(const std::string &num)
{
    number = num;
}