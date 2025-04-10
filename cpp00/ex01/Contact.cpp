/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:23:17 by pkostura          #+#    #+#             */
/*   Updated: 2025/04/01 14:44:58 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".includes.hpp"

Contact::Contact()
{
	std::cout << "Contact constructor\n";
}

Contact::~Contact()
{
	std::cout << "Contact destructor for " << this->first_name << "\n";
}

// Getters
std::string Contact::get_first_name() const
{
    if (this->first_name.length() > 10)
        return this->first_name.substr(0, 9) + ".";
    return this->first_name;
}

std::string Contact::get_last_name() const
{
    if (this->last_name.length() > 10)
        return this->last_name.substr(0, 9) + ".";
    return this->last_name;
}

std::string Contact::get_number() const
{
    if (this->number.length() > 10)
        return this->number.substr(0, 9) + ".";
    return this->number;
}

std::string Contact::get_darkest_secret() const
{
    return this->darkest_secret;
}

// Setters
void Contact::set_first_name(const std::string &name)
{
    this->first_name = name;
}

void Contact::set_last_name(const std::string &name)
{
    this->last_name = name;
}

void Contact::set_number(const std::string &num)
{
    this->number = num;
}

void Contact::set_darkest_secret(const std::string &secret)
{
	this->darkest_secret = secret;
}