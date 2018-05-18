#include "cRenderObject.h"

cRenderObject::cRenderObject(sf::VideoMode mode, const sf::String &title, int style, const sf::ContextSettings &settings) : sf::RenderWindow(mode,title,style,settings)
{
    //ctor
}

cRenderObject::~cRenderObject()
{
    //dtor
}

void cRenderObject::AddObject(sf::Drawable* drawable)
{
    this->RenderTargets.push_back(drawable);
}

void cRenderObject::RemoveObject(sf::Drawable* drawable)
{
    int Size = this->RenderTargets.size();

    for(int i = 0; i < Size; i++)
    {
        if(this->RenderTargets[i] == drawable)
        {
            this->RenderTargets.erase(this->RenderTargets.begin() + i);
            break;
        }
    }
}

void cRenderObject::RemoveAndDeleteObject(sf::Drawable* drawable)
{
    int Size = this->RenderTargets.size();

    for(int i = 0; i < Size; i++)
    {
        if(this->RenderTargets[i] == drawable)
        {
            this->RenderTargets.erase(this->RenderTargets.begin() + i);
            break;
        }
    }

    delete drawable;
}

void cRenderObject::StartThread()
{
    this->FrameTimer = new sf::Clock;

    this->RenderThread = new sf::Thread(&cRenderObject::MainThread,this);
    this->RenderThread->launch();
}

void cRenderObject::MainThread(cRenderObject *t_this)
{
    //we active the window so we can draw
    t_this->setActive(true);

    //we Loop as long as the window is open
    while(t_this->isOpen())
    {
        while(t_this->shouldPause)
        {
            sf::sleep(sf::milliseconds(5));
            t_this->isPaused = true;
        }
        t_this->isPaused = false;

        //Gets the frametime
        t_this->FrameTime = t_this->FrameTimer->restart().asMicroseconds();

        //Clears the Screen
        t_this->clear();

        //We retrieve the Size of the Vector for the Loop, if we do it in the Loop our program can randomly crash
        int Size = t_this->RenderTargets.size();

        //Loop through each element in the vector
        for(int i = 0; i < Size; i++)
        {
            //We draw each one
            t_this->draw(*t_this->RenderTargets[i]);
        }

        //We display everything we drew
        t_this->display();
    }
}

void cRenderObject::Pause()
{
    this->shouldPause = true;
}

void cRenderObject::Resume()
{
    this->shouldPause = false;
}

void cRenderObject::WaitForPaused()
{
    while(!this->isPaused)
        sf::sleep(sf::milliseconds(5));
}

int cRenderObject::GetFramerate()
{
    return 1000000 / this->FrameTime;
}

int cRenderObject::GetFrametime()
{
    return this->FrameTime;
}
