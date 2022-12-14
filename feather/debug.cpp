#include "debug.h"

int Log(const char *message){
	std::cout << message << std::endl;
	return 0;
}

int Crash(const char *message){
	std::cout << red << "FATAL ERROR: " << reset << message << ". Engine will now shut down." << std::endl;
	running = false;
	return 0;
}
