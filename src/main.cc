#include "pios.h"

int main(int argc, char const *argv[])
{
	Pios pios;
	pios.run();	
	std::cout << "Terminating" << std::endl;
	return 0;
}