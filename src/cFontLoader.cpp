#include "cFontLoader.h"

cFontLoader::cFontLoader()
{
    //ctor
}

cFontLoader::~cFontLoader()
{
    //dtor
}

void cFontLoader::LoadFont(const char* FontName,const char* path)
{
    cIDFont *Buffer = new cIDFont;

    Buffer->loadFromFile(path);

    Buffer->setFontID(FontName);

    this->fonts.push_back(Buffer);
}

sf::Font& cFontLoader::GetFont(const char* FontName)
{

    int ArraySize = this->fonts.size();

    int argStringSize = 0;
    for(;FontName[argStringSize] != 0;argStringSize++);


    for(int i = 0; i < ArraySize; i++)
	{
		const char* targetString = this->fonts[i]->getFontID();

		int targetStringSize = 0;
		for(;targetString[targetStringSize] != 0;targetStringSize++);

		if(argStringSize != targetStringSize)
			continue;

		bool isEqual = true;

		for(int ii = 0; ii < argStringSize; ii++)
		{
			if(targetString[ii] != FontName[ii])
			{
				isEqual = false;
				break;
			}
		}

		if(isEqual)
		{
			return *this->fonts[i];
		}
	}
	std::cout << "FONT NOT FOUND: " << FontName << std::endl;
	throw 0;
}
