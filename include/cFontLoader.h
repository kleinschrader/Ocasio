#ifndef CFONTLOADER_H
#define CFONTLOADER_H

#include <sfml/Graphics.hpp>
#include "cIDFont.h"

#include <vector>

#include <iostream>

class cFontLoader
{
    public:
        cFontLoader();
        virtual ~cFontLoader();

        void LoadFont(const char* FontName, const char *path);
        sf::Font& GetFont(const char* FontName);

    private:

        std::vector<cIDFont*> fonts;
};

#endif // CFONTLOADER_H
