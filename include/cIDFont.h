#ifndef CIDFONT_H
#define CIDFONT_H

#include <SFML/Graphics.hpp>

class cIDFont : public sf::Font
{
	public:
		cIDFont();
		virtual ~cIDFont();

		void setFontID(const char*);
		const char* getFontID();

	private:
		const char* FontID;
};

#endif // CIDFONT_H
