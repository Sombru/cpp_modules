#ifndef BASE_HPP
# define BASE_HPP

class Base
{
private:
	/* data */
public:
	Base();
	virtual ~Base();
	
};

Base *generate(void); // randomly instantiates A, B or C, and returns a Base pointer
void identify(Base *p); // prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base &p); // prints the actual type of the object referenced by p: "A", "B", or "C".


#endif