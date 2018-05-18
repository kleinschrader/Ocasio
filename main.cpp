#include <iostream>
#include <SFML/Graphics.hpp>
#include <cRenderObject.h>
#include <cFontLoader.h>
#include <cTextureLoader.h>
#include <cMenuElement.h>

int main()
{
	//Game name: Ocasio

    sf::Texture *LoadingImage = new sf::Texture;
    LoadingImage->loadFromFile("resource/textures/Loading.png");
    sf::Sprite *LoadingSprite = new sf::Sprite(*LoadingImage);
    LoadingSprite->setOrigin(sf::Vector2f(LoadingSprite->getLocalBounds().width/2,LoadingSprite->getLocalBounds().height/2));
    LoadingSprite->setPosition(500/2,500/2);

    cRenderObject MainWindow(sf::VideoMode(500,500),"TITLE");
    MainWindow.setActive(false);
    MainWindow.StartThread();

    MainWindow.AddObject(LoadingSprite);

    cFontLoader FontLoader;
    cTextureLoader TextureLoader;

    FontLoader.LoadFont(cFontLoader::impact,"resource/fonts/impact.ttf");

    //Load menu elements with borders
    TextureLoader.LoadTexture(cTextureLoader::MENU_LEFT_BORDER,"resource/textures/menu/background/border/left.png");
    TextureLoader.LoadTexture(cTextureLoader::MENU_RIGHT_BORDER,"resource/textures/menu/background/border/right.png");
    TextureLoader.LoadTexture(cTextureLoader::MENU_MIDDLE_BORDER,"resource/textures/menu/background/border/straight.png");


    //Load menu elements without borders
    TextureLoader.LoadTexture(cTextureLoader::MENU_LEFT_NOBORDER,"resource/textures/menu/background/noborder/left.png");
    TextureLoader.LoadTexture(cTextureLoader::MENU_RIGHT_NOBORDER,"resource/textures/menu/background/noborder/right.png");
    TextureLoader.LoadTexture(cTextureLoader::MENU_MIDDLE_NOBORDER,"resource/textures/menu/background/noborder/straight.png");

    MainWindow.Pause();
    MainWindow.WaitForPaused();

    MainWindow.RemoveAndDeleteObject(LoadingSprite);

    sf::Text Title;
    Title.setFont(FontLoader.GetFont(cFontLoader::impact));
    Title.setCharacterSize(50);
    Title.setString("Ocasio");
	Title.setOrigin(Title.getGlobalBounds().width/2,0);
	Title.setPosition(250,50);


    cMenuElement *MainBar = new cMenuElement(&TextureLoader,25,50,450,2,&Title);

    MainWindow.AddObject(MainBar);

    MainWindow.Resume();

    while(MainWindow.isOpen())
    {
        sf::Event PollEvent;
        while(MainWindow.pollEvent(PollEvent))
        {
            if(PollEvent.type == sf::Event::Closed)
                MainWindow.close();
        }

        std::cout << "Window Framerate: " << MainWindow.GetFramerate() << std::endl;

    }

    return 0;
}
