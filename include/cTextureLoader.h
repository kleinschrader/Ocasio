#ifndef CTEXTURELOADER_H
#define CTEXTURELOADER_H

#include <SFML/Graphics.hpp>
#include "cIDTexture.h"

#include <vector>

class cTextureLoader
{
    public:
        cTextureLoader();
        virtual ~cTextureLoader();

        //Loads the Texture
        void loadTexture(const char* nameOfTextue, const char *path);

        //return the Texture
        const sf::Texture* getTexture(const char* nameOfTextue);

    private:
        std::vector<cIDTexture*> textures;
};

#endif // CTEXTURELOADER_H
