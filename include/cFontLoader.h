#ifndef CFONTLOADER_H
#define CFONTLOADER_H

#include <sfml/Graphics.hpp>

#include <vector>

class cFontLoader
{
    public:
        cFontLoader();
        virtual ~cFontLoader();

        void LoadFont(int FontToLoad, const char *path);
        sf::Font& GetFont(int Font);

        enum Fonts
        {
            impact,
            MAXSIZE
        };

    private:

        sf::Font *FontArray;
};

#endif // CFONTLOADER_H
