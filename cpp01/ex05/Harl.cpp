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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specil-"
	" ketchup burger. I really do!\n";
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
	" enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
	" years, whereas you started working here just last month.\n";
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
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

	int i = atoi(level.c_str());
	
	(this->*funcPtr[i])();
	
}

