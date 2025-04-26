#include "Brain.hpp"

Brain::Brain()
: has_ideas(false)
{
	std::cout << "Brain constructor\n";
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor\n";
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = copy.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
    {
        std::cout << "Brain assignment operator\n";
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = copy.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor\n";
}

std::string Brain::getIdea(int index) const
{
	// std::cout << "brain idea: " << ideas[index] << '\n';
    if (index < 0 || index >= 99)
    {
        std::cerr << "Invalid index\n";
    }
    return this->ideas[index];
}

void Brain::setIdea(std::string idea, int index)
{
	this->ideas[index] = idea;
}

void Brain::fillWithRandomIdeas()
{
    const std::string words[26] = {
        "apple", "banana", "cherry", "dog", "elephant", "flower", "guitar", "house", "island", "jungle",
        "kite", "lemon", "mountain", "notebook", "ocean", "piano", "queen", "river", "sun", "tree",
        "umbrella", "violin", "waterfall", "xylophone", "yacht", "zebra"
    };

	int i = 0;
	int k = 0;
	while (i < 99)
	{
		if (k > 25)
			k = 0;
		ideas[i] = words[k];
		i++;
		k++;
	}
	has_ideas = true;
	// std::cout << "brain idea: " << ideas[4] << '\n';
    std::cout << "Brain filled with random ideas.\n";
}
