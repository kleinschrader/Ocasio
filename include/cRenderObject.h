#ifndef CRENDEROBJECT_H
#define CRENDEROBJECT_H

#include <SFML/graphics.hpp>
#include <SFML/system.hpp>

#include <vector>

class cRenderObject : public sf::RenderWindow
{
    public:
    	//Mainwindow Constructor
        cRenderObject(sf::VideoMode mode, const sf::String &title, int style=sf::Style::Default, const sf::ContextSettings &settings=sf::ContextSettings());

        //deonstructor, not used
        virtual ~cRenderObject();

        //Start the thread
        void startThread();


        //add an object to our Rendering List
        void addObject(sf::Drawable*);

        //Removes an Object from the Render List (it dosent get deleted
        void removeObject(sf::Drawable*);

        //Removes this Object and deletes this
        void removeAndDeleteObject(sf::Drawable*);


        //Wait on the Caller Thread until the Rendering thread is paused
        void waitForPaused();

        //Pause the rendering thread. NOTE: it wont stop immediately, use wait for Paused
        void pause();

        //Resumes the rendering Thread
        void resume();

        //Returns the Framerate
        int getFramerate();

        //Returns the Frametime
        int getFrametime();
    private:
    	//The Mainthread, call it using startThread
        static void mainThread(cRenderObject*);

		//Variable for out dynamic Thread
        sf::Thread *renderThread;

        //Here we store all drawables
        std::vector <sf::Drawable*>renderTargets;

        //The Clock we use to calculate the Frametime
        sf::Clock *frameTimer;

        //Here we store the last frametime
        int frameTime = 0;

        //Creates a block for the Rendering Thread so it pauses
        bool shouldPause = false;
        //true if the Thread is paused, not just if it should pause
        bool isPaused = false;
};

#endif // CRENDEROBJECT_H
