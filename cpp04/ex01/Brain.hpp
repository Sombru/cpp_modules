#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	~Brain();

	std::string getIdea(int index) const;
	void fillWithRandomIdeas();
};




#endif