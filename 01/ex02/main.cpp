#include <cctype>
#include <iostream>

int	main(void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPtr = &brain;
	std::string &stringRef = brain;

	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "The memory address of the string      : " << &brain << std::endl;
	std::cout << "The memory address held by stringPTR. : " << stringPtr << std::endl;
	std::cout << "The memory address held by stringREF. : " << &stringRef << std::endl;

	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "The value of the string variable   : " << brain << std::endl; 
	std::cout << "The value pointed to by stringPTR. : " << *stringPtr << std::endl;
	std::cout << "The value pointed to by stringREF. : " << stringRef << std::endl;

	std::cout << "--------------------------------------------------" << std::endl;
	return (0);
}
