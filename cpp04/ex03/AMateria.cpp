#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type)
: mType(type)
{
    std::cout << "AMateria constructor\n";
}

std::string const &AMateria::getType() const
{
	return mType;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Using AMateria on " << target.getName() << '\n';
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor\n";
}