#ifndef CMENUELEMENT_H
#define CMENUELEMENT_H

#include <sfml/Graphics.hpp>

#include "cTextureLoader.h"

class cMenuElement : public sf::Drawable
{
    public:
        cMenuElement(cTextureLoader* TextureLoader, int PosX, int PosY, int Width, float yScale, sf::Text* Text);
        virtual ~cMenuElement();
    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::RectangleShape *Left_side;
        sf::RectangleShape *Right_side;
        sf::RectangleShape *Middle;

        cTextureLoader* TextureLoader;
        int PosX,PosY,Width;
        sf::Text *Text;
};

#endif // CMENUELEMENT_H
