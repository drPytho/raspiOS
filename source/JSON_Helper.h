#ifndef JSON_HELPER_H_
#define JSON_HELPER_H_ 

#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>

namespace JSON_Helper
{
	
	class JSON_BASE
	{
	public:
		JSON();
		~JSON();
		
		virtual JSObject* getJSON()=0;
	};

	/*
	movie:{
		Title:"Title",
		Path:"/media/usb0/title.mp4",
		IMG_Path:"/media/usb0/title.jpg",
		Duration:451234(s),
		resolution:"640x480"
	};
	*/

	class JSON_MOVIE : public JSON_BASE
	{
	public:
		JSON_MOVIE()
		{

		}

		JSON_MOVIE(std::string Title, std::string Path, std::string IMG_Path, int durationS, std::string Resolution)
		{
			this->Title = Title;
			this->Path = Path;
			this->IMG_Path = IMG_Path;
			this->durationS = durationS;
			this->Resolution = Resolution;
		}

		~JSON_MOVIE();
		
		JSObject* getJSON()
		{
			JSObject* ret = new JSObject;
			ret->setProperty(WSLit("title"), 		WSLit(Title));
			ret->setProperty(WSLit("path"), 		WSLit(Path));
			ret->setProperty(WSLit("img_path"), 	WSLit(IMG_Path));
			ret->setProperty(WSLit("duration"), 	durationS);
			ret->setProperty(WSLit("resolution"), 	WSLit(Resolution));

			return JSObject;
		}

		std::string getTitle() 					const {return Title;}
		std::string getPath()					const {return Path;}
		std::string getIMG_Path()				const {return Path;}
		int getDuration()						const {return durationS;};
		std::string getResolution()				const {return Resolution;}

		void setTitle(std::string value)		{Title = value;}
		void setPath(std::string value)			{Path = value;}
		void setIMG_Path(std::string value)		{IMG_Path = value;}
		void setDuration(int value)				{durationS = value;}
		void setResolution(std::string value)	{Resolution = value;}


	private:
		std::string Title;
		std::string Path;
		std::string IMG_Path;
		int durationS;
		std::string Resolution;
	};

	/*
	music:{
		Title:"Title",
		Path:"/media/usb0/title.mp3",
		Duration:451234(s)
	};
	*/

	class JSON_MUSIC : public JSON_BASE
	{
	public:
		JSON_MUSIC()
		{

		}

		JSON_MUSIC(std::string Title, std::string Path, int durationS)
		{
			this->Title = Title;
			this->Path = Path;
			this->durationS = durationS;
		}

		~JSON_MUSIC();
		
		JSObject* getJSON()
		{
			JSObject* ret = new JSObject;
			ret->setProperty(WSLit("title"), 		WSLit(Title));
			ret->setProperty(WSLit("path"), 		WSLit(Path));
			ret->setProperty(WSLit("duration"), 	durationS);

			return JSObject;
		}

		std::string getTitle() 					const {return Title;}
		std::string getPath()					const {return Path;}
		int getDuration()						const {return durationS;};

		void setTitle(std::string value)		{Title = value;}
		void setPath(std::string value)			{Path = value;}
		void setDuration(int value)				{durationS = value;}


	private:
		std::string Title;
		std::string Path;
		int durationS;
	};

	/*
	emu:{
		Title:"Title",
		Path:"/media/usb0/title.mp4",
		emulator:"GBA"
	};
	*/

	class JSON_EMU	: public JSON_BASE
	{
	public:
		JSON_EMU()
		{

		}

		JSON_EMU(std::string Title, std::string Path, std::string emulator)
		{
			this->Title = Title;
			this->Path = Path;
			this->emulator = emulator;
		}

		~JSON_EMU();
		
		JSObject* getJSON()
		{
			JSObject* ret = new JSObject;
			ret->setProperty(WSLit("title"), 		WSLit(Title));
			ret->setProperty(WSLit("path"), 		WSLit(Path));
			ret->setProperty(WSLit("duration"), 	duration);

			return JSObject;
		}

		std::string getTitle() 					const {return Title;}
		std::string getPath()					const {return Path;}
		std::string getEmulator()				const {return emulator;};

		void setTitle(std::string value)		{Title = value;}
		void setPath(std::string value)			{Path = value;}
		void setEmulator(std::string value)		{emulator = value;}


	private:
		std::string Title;
		std::string Path;
		std::string emulator;
		
	};
}

#endif