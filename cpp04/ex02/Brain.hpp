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

	void setIdea(std::string idea, int index);
	std::string getIdea(int index) const;
	void fillWithRandomIdeas();

	bool has_ideas;
};




#endif