#include "cMenuElement.h"
#include <iostream>

cMenuElement::cMenuElement(cTextureLoader* TextureLoader, int PosX, int PosY, int Width, float yScale, sf::Text* Text)
{
    this->TextureLoader = TextureLoader;
    this->PosX = PosX;
    this->PosY = PosY;
    this->Width = Width;
    this->Text = Text;

    this->Left_side = new sf::RectangleShape;
    this->Middle = new sf::RectangleShape;
    this->Right_side = new sf::RectangleShape;

    this->Left_side->setSize(sf::Vector2f(30,30));
    this->Left_side->setPosition(this->PosX,this->PosY);
    this->Left_side->setScale(1,yScale);

    this->Middle->setSize(sf::Vector2f(this->Width - 60, 30));
    this->Middle->setPosition(this->PosX + 30,this->PosY);
    this->Middle->setScale(1,yScale);

    this->Right_side->setSize(sf::Vector2f(30,30));
    this->Right_side->setPosition(this->PosX + this->Width - 30,this->PosY);
    this->Right_side->setScale(1,yScale);

    this->Left_side->setTexture(TextureLoader->GetTexture(cTextureLoader::MENU_LEFT_BORDER));
    this->Middle->setTexture(TextureLoader->GetTexture(cTextureLoader::MENU_MIDDLE_BORDER));
    this->Right_side->setTexture(TextureLoader->GetTexture(cTextureLoader::MENU_RIGHT_BORDER));
}

cMenuElement::~cMenuElement()
{
    delete this->Left_side;
    delete this->Middle;
    delete this->Right_side;
}

void cMenuElement::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*this->Left_side);
    target.draw(*this->Right_side);
    target.draw(*this->Middle);

    if(this->Text != nullptr)
    {
		target.draw(*this->Text);
    }
}
