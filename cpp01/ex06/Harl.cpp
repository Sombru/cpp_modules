#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "HARL HAS BEEN AWAKEN\n";
}

Harl::~Harl()
{
	std::cout << "HARL IS BACK to slep\n";
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specil-"
	" ketchup burger. I really do!\n\n";
}

void Harl::info()
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
	" enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for"
	" years, whereas you started working here just last month.\n\n";
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
	void (Harl::*funcPtr[])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;

	while (i < 4)
	{
		if (level == levels[i])
			break ;
		i++;
	}
	
	switch (i)
	{
	case 0:
		for (int i = 0; i < 4;i++)
			(this->*funcPtr[i])();
		break;
	case 1:
		for (int i = 1; i < 4;i++)
			(this->*funcPtr[i])();
		break;
	case 2:
		for (int i = 2; i < 4;i++)
			(this->*funcPtr[i])();
		break;
	case 3:
		for (int i = 3; i < 4;i++)
			(this->*funcPtr[i])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
	
}

