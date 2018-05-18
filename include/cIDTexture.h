#ifndef CIDTEXTURE_H
#define CIDTEXTURE_H

#include <sfml/Graphics.hpp>


class cIDTexture : public sf::Texture
{
	public:
		cIDTexture();
		virtual ~cIDTexture();

		void setTextureID(const char*);
		const char* getTextureID();

	private:
		const char* TextureID;
};

#endif // CIDTEXTURE_H
