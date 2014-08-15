#ifndef LPI_H
#define LPI_H 

#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>

namespace LPI
{	
	bool StartEmulator(std::string game);
	bool ChangeSetting(std::string setting, std::string value);
	std::vector<std::string> getFilesInFolder(std::string paths[]);

	typedef char fType;

	enum
	{
		D_VIDEO 	= 1 << 0,
		D_AUDIO 	= 1 << 1,
		D_EMULATOR 	= 1 << 2,
		D_GRAPHICS	= 1 << 3,
		D_OTHER 	= 1 << 4
	};

	//List of endings 
	const char* const VIDEO[] 		= {"mp4", "avi"};					const int VIDEO_SIZE = 2;
	const char* const AUDIO[] 		= {"mp3", "wav", "raw"};			const int AUDIO_SIZE = 3;
	const char* const EMULATOR[] 	= {"ns", "nes", "snes"};			const int EMULATOR_SIZE = 3;
	const char* const GRAPHICS[] 	= {"png", "bmp", "jpg", "jpeg"};	const int GRAPHICS_SIZE = 4;


	fType getFileType(char* extention);
};


#endif