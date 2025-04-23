#include "Brain.hpp"

Brain::Brain()
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
    if (index < 0 || index >= 100)
    {
        std::cerr << "Invalid index: " << index << ". Returning a random idea.\n";
        index = std::rand() % 100;
    }
    return this->ideas[index];
}

void Brain::fillWithRandomIdeas()
{
    const std::string words[] = {
        "apple", "banana", "cherry", "dog", "elephant", "flower", "guitar", "house", "island", "jungle",
        "kite", "lemon", "mountain", "notebook", "ocean", "piano", "queen", "river", "sun", "tree",
        "umbrella", "violin", "waterfall", "xylophone", "yacht", "zebra"
    };
    const int wordCount = sizeof(words) / sizeof(words[0]);

    // Seed the random number generator
    std::srand(std::time(0));

    for (int i = 0; i < 100; i++)
    {
        // Generate a random index to pick a word
        int randomIndex = std::rand() % wordCount;
        ideas[i] = words[randomIndex];
    }

    std::cout << "Brain filled with random ideas.\n";
}
