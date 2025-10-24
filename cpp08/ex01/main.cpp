#include "Span.hpp"

// int main()
// {
// 	unsigned int size = 15;
// 	Span sp = Span(size);
// 	sp.fillWithRandomNumbers();
// 	for (unsigned int i = 0; i < size; i++)
// 	{
// 		std::cout << sp[i] << '\n';
// 	}
// 	// std::cout << sp.shortestSpan() << std::endl;
// 	// std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int main()
{
Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
return 0;
}