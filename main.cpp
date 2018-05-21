#include <iostream>
#include <SFML/Graphics.hpp>
#include "cRenderObject.h"
#include "cFontLoader.h"
#include "cTextureLoader.h"
#include "cMenuElement.h"
#include "Textf.h"
#include "cAnimationManager.h"

int main()
{
    sf::Texture *LoadingImage = new sf::Texture;
    LoadingImage->loadFromFile("resource/textures/Loading.png");
    sf::Sprite *LoadingSprite = new sf::Sprite(*LoadingImage);
    LoadingSprite->setOrigin(sf::Vector2f(LoadingSprite->getLocalBounds().width/2,LoadingSprite->getLocalBounds().height/2));
    LoadingSprite->setPosition(500/2,500/2);

    cRenderObject MainWindow(sf::VideoMode(500,500),"TITLE");
    MainWindow.setActive(false);
    MainWindow.startThread();

    MainWindow.addObject(LoadingSprite);

    cFontLoader FontLoader;
    cTextureLoader TextureLoader;

    FontLoader.LoadFont("impact","resource/fonts/impact.ttf");

    //Load menu elements with borders
    TextureLoader.loadTexture("MENU_LEFT_BORDER","resource/textures/menu/background/border/left.png");
    TextureLoader.loadTexture("MENU_RIGHT_BORDER","resource/textures/menu/background/border/right.png");
    TextureLoader.loadTexture("MENU_MIDDLE_BORDER","resource/textures/menu/background/border/straight.png");
	TextureLoader.loadTexture("EXAMPLE_PERSON_THUMPS_UP","resource/animations/examplePerson/thumpsup/thumpsup.png");
	TextureLoader.loadTexture("EXAMPLE_PERSON_SHOOTING","resource/animations/examplePerson/shooting/shooting.png");

    MainWindow.pause();
    MainWindow.waitForPaused();

    MainWindow.removeAndDeleteObject(LoadingSprite);

    sf::Text Title;
    Title.setFont(FontLoader.GetFont("impact"));
    Title.setCharacterSize(50);
    Title.setString("Ocasio");
	Title.setOrigin(Title.getGlobalBounds().width/2,0);
	Title.setPosition(250,50);


	sf::RectangleShape Shape;
	Shape.setSize(sf::Vector2f(500,417));

	cAnimationManager Tester(&Shape,&TextureLoader,"THUMPS_UP");
	Tester.loadAnimation("SHOOTING","resource/animations/examplePerson/shooting/shooting.anim",false);
	Tester.loadAnimation("THUMPS_UP","resource/animations/examplePerson/thumpsup/thumpsup.anim",true);
	Tester.playAnimation("THUMPS_UP");

    cMenuElement *MainBar = new cMenuElement(&TextureLoader,25,50,450,2,&Title);

    int FPS = 0;
    int Frametime = 0;

    Textf *TextL = new Textf;
    TextL->setFont(FontLoader.GetFont("impact"));
    TextL->setString("%c Engine-Framework | FPS: %i | Frametime: %ims");

    const char* Ocasio = "Ocasio";
    TextL->addVaribale((void*)Ocasio);
    TextL->setPercision(3);
    TextL->addVaribale(&FPS);
    TextL->addVaribale(&Frametime);
    TextL->setCharacterSize(10);

    MainWindow.addObject(TextL);

    MainWindow.addObject(MainBar);

    MainWindow.addObject(&Shape);

    MainWindow.resume();

    while(MainWindow.isOpen())
    {
        sf::Event PollEvent;
        while(MainWindow.pollEvent(PollEvent))
        {
            if(PollEvent.type == sf::Event::Closed)
                MainWindow.close();
			if(PollEvent.type == sf::Event::KeyPressed)
			{
				if(PollEvent.key.code == sf::Keyboard::Space)
 					Tester.playAnimation("SHOOTING");
			}
        }

        Tester.Update();

        FPS = MainWindow.getFramerate();
        Frametime = MainWindow.getFrametime();
        TextL->UpdateString();
    }

    return 0;
}
