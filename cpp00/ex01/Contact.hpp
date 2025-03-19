/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:55:11 by pkostura          #+#    #+#             */
/*   Updated: 2025/03/19 11:25:53 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string number;
	
public:
	Contact(void); // Constructor
	~Contact(void); // Destructor
	
	// getters methods(functios)
	std::string const &get_first_name() const;
	std::string const &get_last_name() const;
	std::string const &get_number() const;
	
	// setters
	void set_first_name(const std::string &name);
    void set_last_name(const std::string &name);
    void set_number(const std::string &num);
};

#endif