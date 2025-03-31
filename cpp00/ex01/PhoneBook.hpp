/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:47:16 by pkostura          #+#    #+#             */
/*   Updated: 2025/03/31 11:06:26 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


class PhoneBook // class - describes the structure
{
private:
	Contact contacts[8];
	int		index;
	int		total_contacts;
	
public:
	PhoneBook(void);
	~PhoneBook(void);

	bool is_running;
	void print_input(const std::string input);
	void match_input(const std::string input);
	void display_contacts();
	void add_contact();
};

#endif