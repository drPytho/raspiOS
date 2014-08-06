#include "pios.h"

Pios::Pios():
	userInterface(new ui("Window Title Here", 640, 480, false, "localhost/local/main.html"))
{
	//Create a new UI here
}

Pios::~Pios()
{
	
}

void Pios::run()
{
	userInterface->start();
}

void Pios::Input()
{
	
}

void Pios::Update()
{
	
}








	