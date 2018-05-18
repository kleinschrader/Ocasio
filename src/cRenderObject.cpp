#include "cRenderObject.h"

cRenderObject::cRenderObject(sf::VideoMode mode, const sf::String &title, int style, const sf::ContextSettings &settings) : sf::RenderWindow(mode,title,style,settings)
{
    //ctor
}

cRenderObject::~cRenderObject()
{
    //dtor
}

void cRenderObject::addObject(sf::Drawable* drawable)
{
	//adds an drawable Object to the end of the Vectir
    this->renderTargets.push_back(drawable);
}

void cRenderObject::removeObject(sf::Drawable* drawable)
{
	//Gets the vector size
    int vectorSize = this->renderTargets.size();

    //Loop through every Object
    for(int i = 0; i < vectorSize; i++)
    {
    	//if the element at i the same as the argument?
        if(this->renderTargets[i] == drawable)
        {
        	//if yes remove it from the vector and stop the for loop
            this->renderTargets.erase(this->renderTargets.begin() + i);
            break;
        }
    }
}

void cRenderObject::removeAndDeleteObject(sf::Drawable* drawable)
{
	//Remove the Object from the vector
	this->removeObject(drawable);

	//delete the Object from memory
    delete drawable;
}

void cRenderObject::startThread()
{
	//Creates the Frame Timer
    this->frameTimer = new sf::Clock;

    //Create a Thread of the function "mainThread" with this Object as an argument
    //So we can reference this in a static Function
    this->renderThread = new sf::Thread(&cRenderObject::mainThread,this);

    //Launches the thread.
    this->renderThread->launch();
}

void cRenderObject::mainThread(cRenderObject *t_this)
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
        t_this->frameTime = t_this->frameTimer->restart().asMicroseconds();

        //Clears the Screen
        t_this->clear();

        //We retrieve the Size of the Vector for the Loop, if we do it in the Loop our program can randomly crash
        int vectorSize = t_this->renderTargets.size();

        //Loop through each element in the vector
        for(int i = 0; i < vectorSize; i++)
        {
            //We draw each one
            t_this->draw(*t_this->renderTargets[i]);
        }

        //We display everything we drew
        t_this->display();
    }
}

void cRenderObject::pause()
{
	//Pauses the Rendering thread
    this->shouldPause = true;
}

void cRenderObject::resume()
{
	//Resumes it
    this->shouldPause = false;
}

void cRenderObject::waitForPaused()
{
	//Wait for as long as the Thread is not Paused.
    while(!this->isPaused)
        sf::sleep(sf::milliseconds(5));
}

int cRenderObject::getFramerate()
{
	//Just calculate the Framerate
    return 1000000 / this->frameTime;
}

int cRenderObject::getFrametime()
{
	//Return the Frametime (in Microsecounds)
    return this->frameTime;
}
