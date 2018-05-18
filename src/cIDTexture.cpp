#include "cIDTexture.h"

cIDTexture::cIDTexture()
{
	//ctor
}

cIDTexture::~cIDTexture()
{
	//dtor
}

void cIDTexture::setTextureID(const char* ID)
{
	this->TextureID = ID;
}

const char* cIDTexture::getTextureID()
{
	return this->TextureID;
}
