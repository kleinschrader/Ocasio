#include "cTextureLoader.h"

cTextureLoader::cTextureLoader()
{
    this->Textures = new sf::Texture[TextureList::MAXSIZE];
}

cTextureLoader::~cTextureLoader()
{
    //dtor
}

void cTextureLoader::LoadTexture(int TextureToLoad, const char* path)
{
    sf::Texture Buffer;

    Buffer.loadFromFile(path);

    this->Textures[TextureToLoad] = Buffer;
}

const sf::Texture* cTextureLoader::GetTexture(int TextureToGet)
{
    return &this->Textures[TextureToGet];
}
