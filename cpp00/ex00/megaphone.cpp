/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:44:11 by pkostura          #+#    #+#             */
/*   Updated: 2025/03/19 09:35:25 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

//cout = character out
//endl = puts a new line and flushes a buffer(hase worse performane than just typing '\n')
	
int	main(int argc, char **argv)
{
	std::string const msg = "* LOUD AND UNBEARABLE NOISE *";
	
	if (argc == 1)
	{
		std::cout << msg << '\n'; 
		return(0);
	}	
		
	for (int i = 1; i < argc; i++)
	{
		for (int y = 0; argv[i][y]; y++)
		{
			if (isalpha(argv[i][y]))
				std::cout << static_cast<char>(toupper((argv[i][y]))); //safe typecasting
			else
				std::cout << argv[i][y];
		}
		
	}
	std::cout << std::endl;
}