#include "LPI.h"

namespace LPI
{	
	bool StartEmulator(std::string game)
	{
		return false;
	}

	bool ChangeSetting(std::string setting, std::string value)
	{
		return false;
	}

/**
 * @description
 *	  gathers all the fils in a number of folders
 * @param [0] paths
 *    An array of paths to search through
 * @param [1] recursive
 *    If it should be a recursive search or not
 * @return
 *    A vector with all the files in it 
 * @throw
 *    Nothing
 *
 * @note
 *    Nees to check for possible memmory leaks with reapeted use.
 */

	std::vector<std::string> getFilesInFolder(std::string paths[], bool recursive)
	{
		std::vector<std::string> Files;
		if(sizeof(paths) == 0)														//Make sure we were provided some paths
			return Files;

		std::vector<std::string> v_paths(paths, paths + sizeof(paths)/sizeof(paths[0]));

		int searchPaths = v_paths.size();											//Get the number of paths
		
		DIR *dp;
		struct dirent *dirp;
		

		for(int i = 0; i < searchPaths; i++)										//Loop through the paths
		{
			if((dp = opendir(paths[i].c_str())) == NULL)									//Directory do not exist.... Or something else
				continue;															//Move on to the next path

			while((dirp = readdir(dp)) != NULL)										//Aslong as we get a new dirent structure there is a new file there with a name on it
			{
				if(dirp->d_type == 0x4)												//if it's a folder
				{
					if(recursive)													//if it's a recursive search
					{
						v_paths.push_back(v_paths[i] + "/" + std::string(dirp->d_name));	//add the dir to the directories to search
						searchPaths++;
					}
				}else{																//Othervise
					Files.push_back(v_paths[i] + "/" + std::string(dirp->d_name));		//Get the god damn name
				}
			}
		}

		return Files;																//Pass it forward :)
	}

	fType getFileType(char* extention)
	{
		//Lowaecase extention
		for(int i = 0; i < (VIDEO_SIZE + AUDIO_SIZE + EMULATOR_SIZE + GRAPHICS_SIZE); i++)
		{
			if (i < VIDEO_SIZE)
			{
				if(!strcmp(VIDEO[i], extention))
					return LPI::D_VIDEO;
			}else if(i < (AUDIO_SIZE + VIDEO_SIZE))
			{
				if(!strcmp(AUDIO[i - VIDEO_SIZE], extention))
					return LPI::D_AUDIO;
			}else if(i < (AUDIO_SIZE + VIDEO_SIZE + EMULATOR_SIZE))
			{
				if(!strcmp(EMULATOR[i - (VIDEO_SIZE + AUDIO_SIZE)], extention))
					return LPI::D_EMULATOR;
			}else if(i < (AUDIO_SIZE + VIDEO_SIZE + EMULATOR_SIZE))
			{
				if(!strcmp(GRAPHICS[i - (VIDEO_SIZE + AUDIO_SIZE + EMULATOR_SIZE)], extention))
					return LPI::D_GRAPHICS;
			}
		}
		return LPI::D_OTHER;
	}

/*
	const char* VIDEO 		= ["mp4", "avi"];					const int VIDEO_SIZE = 2;
	const char* AUDIO 		= ["mp3", "wav", "raw"];			const int AUDIO_SIZE = 3;
	const char* EMULATOR 	= ["ns", "nes", "snes"];			const int EMULATOR_SIZE = 3;
	const char* GRAPHICS 	= ["png", "bmp", "jpg", "jpeg"];	const int GRAPHICS_SIZE = 4;
*/
};