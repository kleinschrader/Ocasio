#include "cIDFont.h"

cIDFont::cIDFont()
{
	//ctor
}

cIDFont::~cIDFont()
{
	//dtor
}

void cIDFont::setFontID(const char* ID)
{
	this->FontID = ID;
}

const char* cIDFont::getFontID()
{
	return this->FontID;
}
