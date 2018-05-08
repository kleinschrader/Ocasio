#ifndef CTEXTURELOADER_H
#define CTEXTURELOADER_H

#include <sfml/Graphics.hpp>

#include <vector>

class cTextureLoader
{
    public:
        cTextureLoader();
        virtual ~cTextureLoader();

        void LoadTexture(int TextureToLoad, const char *path);
        const sf::Texture* GetTexture(int TextureToGet);

        enum TextureList
        {
            MENU_LEFT_BORDER,
            MENU_RIGHT_BORDER,
            MENU_MIDDLE_BORDER,
            MENU_LEFT_NOBORDER,
            MENU_RIGHT_NOBORDER,
            MENU_MIDDLE_NOBORDER,
            MAXSIZE
        };
    private:
        sf::Texture *Textures;
};

#endif // CTEXTURELOADER_H
