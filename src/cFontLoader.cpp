#include "cFontLoader.h"

cFontLoader::cFontLoader()
{
    this->FontArray = new sf::Font[Fonts::MAXSIZE];
}

cFontLoader::~cFontLoader()
{
    //dtor
}

void cFontLoader::LoadFont(int FontToLoad,const char* path)
{
    sf::Font Buffer;

    Buffer.loadFromFile(path);

    this->FontArray[FontToLoad] = Buffer;
}

sf::Font& cFontLoader::GetFont(int Font)
{
    return this->FontArray[Font];
}
