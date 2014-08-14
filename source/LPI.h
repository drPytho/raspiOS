#ifndef LPI_H
#define LPI_H 

#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

namespace LPI
{	
	bool StartEmulator(std::string game);
	bool ChangeSetting(std::string setting, std::string value);
	const std::vector<std::string>& getFilesInFolder(std::string paths[]);

	//std::string getError(){return LPI::error;}
	//std::string error;
};


#endif